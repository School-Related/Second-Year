# Basic calculator code, nothing fancy here. 
# Just a few functions to add, subtract, multiply, and divide.

def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
    return a / b

def factorial(a):
    if a == 0:
        return 1
    else:
        return a * factorial(a - 1)
    
def do_stuff(a, b):
    print(f'{a} + {b} = {add(a, b)}')
    print(f'{a} - {b} = {subtract(a, b)}')
    print(f'{a} * {b} = {multiply(a, b)}')
    print(f'{a} / {b} = {divide(a, b)}')
    print(f'{a}! = {factorial(a)}')
    print()
    
    
if __name__ == '__main__':
    do_stuff(1, 2)
    do_stuff(2, 5)

# Output

# 1 + 2 = 3
# 1 - 2 = -1
# 1 * 2 = 2
# 1 / 2 = 0.5
# 1! = 1

# 2 + 5 = 7
# 2 - 5 = -3
# 2 * 5 = 10
# 2 / 5 = 0.4
# 2! = 2
