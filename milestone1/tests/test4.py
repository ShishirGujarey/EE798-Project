def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

def multiply(x, y):
    return x * y

def divide(x, y):
    if y == 0:
        return "Cannot divide by zero"
    return x / y

def power(x, y):
    return x ** y

def factorial(x):
    if x < 0:
        return "Factorial not defined for negative numbers"
    elif x == 0:
        return 1
    else:
        result = 1
        for i in range(1, x + 1):
            result *= i
        return result

def calculator():
    print("Select operation:")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")
    print("5. Power")
    print("6. Factorial")

    print("Enter choice ")

    num1 = 50
    num2 = 20

    if choice == '1':
        return add(num1, num2)
    elif choice == '2':
        return subtract(num1, num2)
    elif choice == '3':
        return multiply(num1, num2)
    elif choice == '4':
        return divide(num1, num2)
    elif choice == '5':
        return power(num1, num2)
    elif choice == '6':
        return factorial(num1)

result = calculator()
print("The result is:", result)
