from internals import Node
from stdfun import zip
def sep_seq_to_list(a: Node, b: list[Node]) -> list[Node]:
    b.insert(0, a)
    return b
def kv_to_dict(key: Node, value: Node, key_seq: list[Node], value_seq: list[Node]) -> dict[Node, Node]:
    initial = {
        key: value
    }
    initial.update(zip(key_seq, value_seq))
    return initial