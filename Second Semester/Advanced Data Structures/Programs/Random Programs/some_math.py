# x0 = int(input("x0"))
# y0 = int(input("y_0"))
# h = int(input("h"))

x = [0.0]
y = [1.0]
h = 0.2
end_x = 0.4
# x_n = int(input("till what value of x"))


def f_X(x, y):
    # print(x - pow(y, 2))
    return x - pow(y, 2)


def find_y_n(y, x, h, n):
    return y[n - 1] + h * f_X(x[n - 1], y[n - 1])


def euler_method(y, x, h, end_x):
    no_of_iterations = int(end_x / h)
    for i in range(1, no_of_iterations + 5):
        x.append(h + x[i - 1])
        y.append(find_y_n(y, x, h, i))


euler_method(y, x, h, end_x)
print(y)
