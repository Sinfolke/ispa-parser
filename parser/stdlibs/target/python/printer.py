"""Portable structural AST rendering for ISPA's Python-target runtime."""
from __future__ import annotations
import dataclasses
import enum
from typing import Any
from .model import Node, RawToken, Variant


def _children(value: Any) -> list[tuple[str, Any]] | None:
    """Named attributes of a user object (plain classes and slotted dataclasses)."""
    if dataclasses.is_dataclass(value) and not isinstance(value, type):
        return [(f.name, getattr(value, f.name)) for f in dataclasses.fields(value)
                if not f.name.startswith('_')]
    attributes = getattr(value, '__dict__', None)
    if attributes is not None:
        return [(k, v) for k, v in attributes.items() if not k.startswith('_')]
    return None


def format_ast(value: Any, *, depth: int = 0, max_depth: int = 32,
               indent: int | None = None, _seen: set[int] | None = None) -> str:
    """Render `value` structurally. `indent=None` gives one line; `indent=2` pretty-prints."""
    if depth > max_depth:
        return '<max depth>'
    if isinstance(value, enum.Enum):
        return f'{type(value).__name__}.{value.name}'
    if isinstance(value, (str, int, float, bool, type(None))):
        return repr(value)
    if _seen is None:
        _seen = set()
    obj_id = id(value)
    if obj_id in _seen:
        return '<cycle>'
    _seen.add(obj_id)

    def sub(v: Any) -> str:
        return format_ast(v, depth=depth + 1, max_depth=max_depth, indent=indent, _seen=_seen)

    def wrap(open_: str, parts: list[str], close: str) -> str:
        if not parts:
            return open_ + close
        if indent is None:
            return open_ + ', '.join(parts) + close
        pad = ' ' * (indent * (depth + 1))
        return open_ + '\n' + ',\n'.join(pad + p for p in parts) + '\n' + ' ' * (indent * depth) + close

    try:
        if isinstance(value, (Node, RawToken)):
            if value.empty():
                return '<empty>'
            return f'{format_ast(value.name(), depth=depth + 1, indent=indent, _seen=_seen)}' \
                   + wrap('(', [sub(value.value)], ')')
        if isinstance(value, Variant):
            return f'Variant[{value.index()}]' + wrap('(', [sub(value.value)], ')')
        if isinstance(value, dict):
            return wrap('{', [f'{sub(k)}: {sub(v)}' for k, v in value.items()], '}')
        if isinstance(value, (list, tuple)):
            left, right = ('[', ']') if isinstance(value, list) else ('(', ')')
            parts = [sub(v) for v in value]
            if isinstance(value, tuple) and len(parts) == 1:
                parts[0] += ','
            return wrap(left, parts, right)
        children = _children(value)
        if children is not None:
            return type(value).__name__ + wrap('(', [f'{k}={sub(v)}' for k, v in children], ')')
        return repr(value)
    finally:
        _seen.remove(obj_id)


class ASTPrinter:
    def __init__(self, stream=None, indent: int | None = None):
        self.stream = stream
        self.indent = indent
        self.parts: list[str] = []

    def node(self, value: Any) -> None:
        self.parts.append(format_ast(value, indent=self.indent))

    def write(self, value: Any) -> None:
        self.parts.append(str(value))

    def __str__(self) -> str:
        return ''.join(self.parts)

    def flush(self) -> str:
        text = str(self)
        if self.stream is not None:
            self.stream.write(text)
        self.parts.clear()
        return text
