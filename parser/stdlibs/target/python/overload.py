"""Small per-module, per-qualified-name runtime dispatcher for generated overloads.

Python normally overwrites definitions with matching names. This keeps overloads
without relying on C++ templates. Erased signatures that cannot be distinguished
raise instead of silently selecting an arbitrary implementation.

Signatures and annotations are resolved once (lazily, on first call), and the
winning implementation is memoised per argument-type tuple, so steady-state
dispatch is a dict lookup rather than inspect.signature() + eval() per call.
"""
from __future__ import annotations
import functools
import inspect
import types
import typing
from typing import Any, Callable

_REGISTRY: dict[tuple[str, str], list['_Candidate']] = {}
_UNION_TYPES = tuple(t for t in (getattr(types, 'UnionType', None),) if t is not None)


def _matches(annotation: Any, value: Any) -> tuple[bool, int]:
    """(accepts, specificity). Annotation must already be resolved (no strings)."""
    if annotation is inspect.Signature.empty or annotation is typing.Any:
        return True, 0
    origin = typing.get_origin(annotation)
    if origin is typing.Union or (_UNION_TYPES and origin in _UNION_TYPES):
        scores = [_matches(t, value) for t in typing.get_args(annotation)]
        valid = [score for yes, score in scores if yes]
        return (bool(valid), max(valid, default=0))
    if origin is not None:
        annotation = origin
    if annotation is None or annotation is type(None):
        return value is None, 1
    if not isinstance(annotation, type):
        return True, 0  # TypeVar, Literal, forward refs we could not resolve, ...
    try:
        ok = isinstance(value, annotation)
    except TypeError:
        return True, 0
    return ok, (2 if type(value) is annotation else 1)


class _Candidate:
    __slots__ = ('fn', 'signature', 'annotations')

    def __init__(self, fn: Callable) -> None:
        self.fn = fn
        self.signature = inspect.signature(fn)
        self.annotations: dict[str, Any] | None = None  # resolved lazily: names may not exist yet

    def resolve(self) -> dict[str, Any]:
        if self.annotations is None:
            resolved = {}
            for name, param in self.signature.parameters.items():
                ann = param.annotation
                if isinstance(ann, str):
                    try:
                        ann = eval(ann, self.fn.__globals__)
                    except (NameError, AttributeError, TypeError, SyntaxError):
                        ann = inspect.Signature.empty  # unresolved: accept anything
                resolved[name] = ann
            self.annotations = resolved
        return self.annotations

    def score(self, args: tuple, kwargs: dict) -> int | None:
        try:
            bound = self.signature.bind(*args, **kwargs)
        except TypeError:
            return None
        annotations = self.resolve()
        total = 0
        for name, value in bound.arguments.items():
            kind = self.signature.parameters[name].kind
            if kind in (inspect.Parameter.VAR_POSITIONAL, inspect.Parameter.VAR_KEYWORD):
                continue
            ok, inc = _matches(annotations[name], value)
            if not ok:
                return None
            total += inc
        return total


def overload(fn: Callable) -> Callable:
    key = (fn.__module__, fn.__qualname__)
    candidates = _REGISTRY.setdefault(key, [])
    code = getattr(fn, '__code__', None)
    # A module reload re-registers the same definition: replace instead of duplicating.
    for i, existing in enumerate(candidates):
        old = getattr(existing.fn, '__code__', None)
        if code is not None and old is not None and \
                (old.co_filename, old.co_firstlineno) == (code.co_filename, code.co_firstlineno):
            candidates[i] = _Candidate(fn)
            break
    else:
        candidates.append(_Candidate(fn))
    cache: dict[tuple, Callable] = {}

    def select(args: tuple, kwargs: dict) -> Callable:
        scored = []
        for candidate in candidates:
            score = candidate.score(args, kwargs)
            if score is not None:
                scored.append((score, candidate.fn))
        if not scored:
            raise TypeError(f'No matching overload of {fn.__qualname__}')
        scored.sort(key=lambda item: item[0], reverse=True)
        if len(scored) > 1 and scored[0][0] == scored[1][0]:
            raise TypeError(f'Ambiguous Python overload of {fn.__qualname__}: '
                            'argument types were erased or duplicate signatures exist')
        return scored[0][1]

    @functools.wraps(fn)
    def dispatcher(*args: Any, **kwargs: Any) -> Any:
        if kwargs:  # keyword calls are rare in generated code: skip the cache
            return select(args, kwargs)(*args, **kwargs)
        signature = tuple(map(type, args))
        target = cache.get(signature)
        if target is None:
            target = select(args, kwargs)
            # Only cache when the choice depends on the types alone (None is its own type).
            if len(cache) < 512:
                cache[signature] = target
        return target(*args)
    # Registering another overload invalidates memoised choices of earlier dispatchers.
    for existing_cache in _CACHES.setdefault(key, []):
        existing_cache.clear()
    _CACHES[key].append(cache)
    return dispatcher


_CACHES: dict[tuple[str, str], list[dict]] = {}
