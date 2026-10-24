"""ISPA LL combinators with the return convention of ispastdlib/parser_ll.hpp.

required/optional -> Node; counted/range/range_optional -> list[Node].
Generated rule callbacks return MatchResult(status=..., node=..., it=cursor).
"""
from __future__ import annotations
from dataclasses import dataclass
from typing import Any, Callable
from .model import MatchResult, Node, RawToken
from .lexer import Lexer, Cursor


class ParseError(RuntimeError):
    """`offset` is a token index; `line`/`column` (1-based) are filled when the lexer is known."""
    def __init__(self, expected: Any, offset: int, line: int | None = None,
                 column: int | None = None):
        where = f'token index {offset}' + (f' (line {line}, column {column})' if line else '')
        super().__init__(f'expected {expected!r} at {where}')
        self.expected, self.offset, self.line, self.column = expected, offset, line, column


@dataclass(slots=True)
class CountSpec:
    # C++ field order: name, count, minimum.
    name: str = ''
    count: int | None = None
    minimum: int = 0

    @classmethod
    def fixed(cls, count: int, minimum: int = 0) -> 'CountSpec':
        if count < 0:
            raise ValueError('repetition count cannot be negative')
        return cls('', count, max(count, minimum))

    @classmethod
    def named(cls, name: str, minimum: int = 0) -> 'CountSpec':
        return cls(name, None, minimum)

    @property
    def maximum(self) -> int | None:
        return self.count


def _as_matched(node: Node) -> Node:
    """A token that matched must not look like "no match": the cursor has already moved,
    so a payload-less token (absent=True) would make required() raise after consuming it."""
    if not node.absent:
        return node
    return Node(node.kind, node.value, node.startpos, node.length,
                node.line, node.column, node.source, False)


class LLParser:
    def __init__(self, lexer: Lexer | None = None) -> None:
        self.lexer = lexer
        self.tree: Any = None
        self.errors: list[ParseError] = []
        self.counters: dict[str, int] = {}

    def parse(self, source: Lexer | str, rule: Callable[[Cursor], MatchResult] | None = None) -> Any:
        lex = source if isinstance(source, Lexer) else self._make_lexer(source)
        self.lexer = lex
        self.errors.clear()
        self.counters.clear()
        start = lex.lazy_iterator()
        match = (rule or getattr(self, 'main'))(start)
        end = match.it if match.it is not None else start
        if not match.status or not end.isEnd():
            raise self._error('complete input', end)
        self.tree = match.node
        return self.tree

    def _error(self, expected: Any, pos: Cursor | None) -> ParseError:
        """Build a ParseError, resolving line/column from the failing token when possible."""
        index = 0 if pos is None else pos.index
        line = column = None
        lex = self.lexer
        if pos is not None and lex is not None:
            try:
                offset = pos.sourcePosition()
                line, column = lex._line(offset), lex._column(offset)
            except Exception:  # never let diagnostics mask the real parse error
                pass
        return ParseError(expected, index, line, column)

    def _make_lexer(self, source: str) -> Lexer:
        lexer_cls = getattr(type(self), 'lexer_type', None)
        if lexer_cls is None:
            raise TypeError('The generated Parser must set lexer_type = Lexer')
        return lexer_cls(source)

    @staticmethod
    def _match(pos: Cursor, expected: Any, callback: Callable | None) -> Node:
        trial = pos.copy()
        if callback is not None:
            result = callback(trial)
            if isinstance(result, MatchResult):
                if result.status:
                    pos.commit(result.it if result.it is not None else trial)
                    return result.node
                return Node()
            if result is None or result is False:
                return Node()
            pos.commit(trial)
            return result
        token = trial.peek()
        if token is None:
            return Node()
        if isinstance(expected, type):
            matches = token.holds(expected) if isinstance(token, RawToken) else isinstance(token, expected)
        else:
            kind = token.name() if hasattr(token, 'name') else getattr(token, 'kind', None)
            matches = kind == expected
        if not matches:
            return Node()
        trial.advance()
        pos.commit(trial)
        node = token.to_node(expected if isinstance(expected, type) else None) \
            if isinstance(token, RawToken) else token
        return _as_matched(node)

    def required(self, pos: Cursor, expected: Any, callback: Callable | None = None,
                 fail: Callable | None = None) -> Node:
        node = self._match(pos, expected, callback)
        if node is not None and not node.empty():
            return node
        if fail is not None:
            fail(pos)
        err = self._error(expected, pos)
        self.errors.append(err)
        raise err

    def optional(self, pos: Cursor, expected: Any, callback: Callable | None = None) -> Node:
        return self._match(pos, expected, callback)

    def counted(self, pos: Cursor, spec: CountSpec | tuple[int, int | None] | int,
                expected: Any, callback: Callable | None = None) -> list[Node]:
        if isinstance(spec, int):
            spec = CountSpec.fixed(spec)
        elif isinstance(spec, tuple):
            spec = CountSpec('', spec[1], spec[0])
        # A named counter that was already captured demands exactly that many items;
        # otherwise `minimum`..`count` is an inclusive range (count=None means unbounded).
        recorded = self.counters.get(spec.name) if spec.name else None
        limit = recorded if recorded is not None else spec.count
        minimum = recorded if recorded is not None else spec.minimum
        original = pos.copy()
        matches: list[Node] = []
        while limit is None or len(matches) < limit:
            before = pos.index
            item = self.optional(pos, expected, callback)
            if item.empty():
                break
            if pos.index == before:
                raise RuntimeError('Zero-length match in repetition')
            matches.append(item)
        if len(matches) < minimum:
            pos.commit(original)
            err = self._error(f'{minimum}..{limit} instances of {expected!r}', pos)
            self.errors.append(err)
            raise err
        if spec.name:
            self.counters.setdefault(spec.name, len(matches))
        return matches

    def range(self, pos: Cursor, expected: Any, callback: Callable | None = None,
              fail: Callable | None = None) -> list[Node]:
        first = self.required(pos, expected, callback, fail)
        tail = []
        while not pos.isEnd():
            before = pos.index
            item = self.optional(pos, expected, callback)
            if item.empty():
                break
            if before == pos.index:
                raise RuntimeError('Zero-width match in range')
            tail.append(item)
        return [first, *tail]

    def range_optional(self, pos: Cursor, expected: Any,
                       callback: Callable | None = None) -> list[Node]:
        items = []
        while not pos.isEnd():
            before = pos.index
            item = self.optional(pos, expected, callback)
            if item.empty():
                break
            if before == pos.index:
                raise RuntimeError('Zero-width match in optional range')
            items.append(item)
        return items

    def skip_spaces(self, pos: Cursor, expected: Any = None) -> None:
        """Use the whitespace token type or provide parser_ws_type on the class."""
        expected = expected if expected is not None else getattr(self, 'parser_ws_type', None)
        if expected is None:
            return
        while not self.optional(pos, expected).empty():
            pass

    def raise_error(self, message: str, pos: Cursor | None = None) -> None:
        err = self._error(message, pos)
        self.errors.append(err)
        raise err


def parse_token_stream(tokens: list, rule: Callable[[Cursor], MatchResult], lexer_type: type[Lexer]) -> Any:
    lexer = lexer_type()
    lexer.tokens = list(tokens)
    lexer._finished = True
    result = rule(lexer.lazy_iterator())
    return result.node if result.status and result.it.isEnd() else None
