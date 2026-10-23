"""Common helpers implemented in the Python subset accepted by ISPA."""


def zip(keys: list, values: list) -> dict:
    """Build a mapping from corresponding elements of two lists.

    This ISPA helper intentionally has the two-list mapping shape used by
    grammar capture utilities, rather than Python's iterator-of-tuples shape.
    If the lists have different lengths, extra elements are ignored.
    """
    result: dict = {}
    i = 0
    while i < len(keys) and i < len(values):
        result[keys[i]] = values[i]
        i += 1
    return result


def range(stop: int) -> list[int]:
    """Return the integers from zero up to, but not including, stop."""
    result: list[int] = []
    i = 0
    while i < stop:
        result.append(i)
        i += 1
    return result


def sum(values: list[int]) -> int:
    """Return the sum of integer values."""
    result = 0
    for value in values:
        result += value
    return result


def min(values: list[int]) -> int:
    """Return the smallest integer in a non-empty list."""
    result = values[0]
    for value in values:
        if value < result:
            result = value
    return result


def max(values: list[int]) -> int:
    """Return the largest integer in a non-empty list."""
    result = values[0]
    for value in values:
        if value > result:
            result = value
    return result


def abs(value: int) -> int:
    """Return the absolute value of an integer."""
    if value < 0:
        return -value
    return value


def all(values: list[bool]) -> bool:
    """Return whether every boolean in the list is true."""
    for value in values:
        if not value:
            return False
    return True


def any(values: list[bool]) -> bool:
    """Return whether at least one boolean in the list is true."""
    for value in values:
        if value:
            return True
    return False


def reversed(values: list[int]) -> list[int]:
    """Return a new list containing the integers in reverse order."""
    result: list[int] = []
    i = len(values) - 1
    while i >= 0:
        result.append(values[i])
        i -= 1
    return result


def sorted(values: list[int]) -> list[int]:
    """Return a stable ascending copy of an integer list."""
    result: list[int] = values.copy()
    i = 1
    while i < len(result):
        value = result[i]
        j = i
        while j > 0 and result[j - 1] > value:
            result[j] = result[j - 1]
            j -= 1
        result[j] = value
        i += 1
    return result

