def zip(keys: list, values: list) -> dict:
    result: dict = {}
    if len(keys) != len(values):
        raise ValueError("keys and values must have the same length")
    for i in range(len(keys)):
        result[keys[i]] = values[i]
    return result

