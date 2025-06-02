from math import sin, cos
def f(p, a, b, c, d, k):
    return p * (sin(a * k + b) + cos(c * k + d) + 2)
p, a, b, c, d, n = list(map(int, input().split()))
ans = 0.0
m = f(p, a, b, c, d, 1)
for i in range(2, n + 1):
    aux = f(p, a, b, c, d, i)
    ans = max(ans, m - aux)
    m = max(m, aux)
print(f'{ans:.6f}')
