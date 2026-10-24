"""Run an imported parser against the host lexer source at its current boundary."""

from __future__ import annotations

from dataclasses import dataclass
from .lexer import Cursor
from .model import MatchResult, Node


@dataclass(frozen=True)
class ExternalRule:
    parser_type: type
    lexer_type: type
    method: str
    value_type: type
    token: bool = False


def external_match(rule: ExternalRule, pos: Cursor) -> MatchResult:
    host = pos.lexer
    if pos.index < len(host.tokens):
        start = host.tokens[pos.index].startpos
    else:
        start = host._cursor.index
    foreign_lexer = rule.lexer_type(host.source)
    foreign_lexer._cursor.index = start
    foreign_lexer.line = foreign_lexer._line(start)
    foreign_lexer.setExternalBoundary(True)
    foreign_pos = foreign_lexer.lazy_iterator()
    if rule.token:
        token = foreign_pos.peek()
        if token is None or not isinstance(token.value, rule.value_type):
            return MatchResult(False, Node(), pos)
        foreign_pos.advance()
        value = token.value
    else:
        parser = rule.parser_type(foreign_lexer)
        result = getattr(parser, rule.method)(foreign_pos)
        if not result.status:
            return MatchResult(False, Node(), pos)
        value = result.node.data() if isinstance(result.node, Node) else result.node
        if not isinstance(value, rule.value_type):
            return MatchResult(False, Node(), pos)
    if foreign_pos.index == 0:
        return MatchResult(False, Node(), pos)
    end = foreign_lexer.tokens[foreign_pos.index - 1].endpos()
    if end <= start:
        return MatchResult(False, Node(), pos)
    # The host lexer cannot tokenize the foreign language. Resume it after the
    # span consumed by the imported parser, leaving the host cursor at its next token.
    host._cursor.index = end
    host.line = host._line(end)
    node = Node(rule.method, value, start, end - start, host._line(start),
                host._column(start), host.source, False)
    return MatchResult(True, node, pos)
