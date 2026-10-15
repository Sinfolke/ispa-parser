class Calculator:
    def __init__(self, value=0):
        self.value = value

    def calculate(self, items):
        result = self.value

        for item in items:
            if item > 0:
                result += item * 2
            elif item < 0:
                result -= -item
            else:
                continue

        return result

def main():
    calculator = Calculator(10)

    try:
        values = [1, -2, 3, 0]
        result = calculator.calculate(values)

        if result > 10:
            print('Large:', result)
        else:
            print('Small:', result)

    except ValueError as error:
        print(error)
    finally:
        print('Finished')

main()
