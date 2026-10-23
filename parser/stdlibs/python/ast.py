"""Small AST-building helpers used by the grammar standard library."""

from internals import Node


def sep_seq_to_list(a: Node, b: list[Node]) -> list[Node]:
    """Convert the head plus repeated separator captures into a flat list."""
    b.insert(0, a)
    return b


def kv_to_dict(key: Node, value: Node, key_seq: list[Node], value_seq: list[Node]) -> dict[Node, Node]:
    """Pair the first key/value with subsequent repeated key/value captures."""
    initial = {
        key: value
    }
    for i in range(len(key_seq)):
        initial[key_seq[i]] = value_seq[i]
    return initial
