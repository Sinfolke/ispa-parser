from internals import Node

def sep_seq_to_list(a: Node, b: list[Node]):
    b.insert(0, a)
    return b