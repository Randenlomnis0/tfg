from math import atan2, acos, sqrt
while True:
    a, b, s, m, n = list(map(int, input().split()))
    if a == 0 and b == 0 and s == 0 and m == 0 and n == 0:
        break
    x = m * a
    y = n * b
    delta = atan2(y, x)
    print(f'{180 * delta / acos(-1.0):.2f} {sqrt(x * x + y * y) / s:.2f}')
