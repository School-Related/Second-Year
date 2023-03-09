# x0 = int(input("x0"))
# y0 = int(input("y_0"))
# h = int(input("h"))

import math

x = [0.0]
y = [1.0]
ey = [1.0]
ex = [0.0]
h = 0.0002
end_x = 0.6
# x_n = int(input("till what value of x"))


def f_X(x, y):
    # print(x - pow(y, 2))
    return math.sqrt(x + y)


def find_y_n(y, x, h, n):
    return y[n - 1] + h * f_X(x[n - 1], y[n - 1])


def find_e_y_n(y, x, h, n):
    return y[n - 1] + (h / 2) * (f_X(x[n - 1], y[n - 1]) + f_X(x[n], y[n]))


def euler_method(y, x, h, end_x):
    no_of_iterations = int(end_x / h)
    for i in range(1, no_of_iterations + 1):
        x.append(h + x[i - 1])
        y.append(find_y_n(y, x, h, i))


def modified_euler(y, x, h, end_x):
    no_of_iterations = int(end_x / h)
    for i in range(1, no_of_iterations + 1):
        x.append(h + x[i - 1])
        ey.append(find_y_n(ey, x, h, i))
        for j in range(50):
            ey[i] = find_e_y_n(ey, x, h, i)


euler_method(y, x, h, end_x)
modified_euler(ey, ex, h, end_x)

print("Values of x")
print(x)
print("Values of y from the regular Method")
print(y)

print("Values of y from the Modified Euler Method")
print(ey)
