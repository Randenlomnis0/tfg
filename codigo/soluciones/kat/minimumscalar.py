T = int(input())
for tcase in range(1, T + 1):
    n = int(input())
    x = list(map(int, input().split()))
    x.sort()
    y = list(map(int, input().split()))
    y.sort()
    ans = 0
    for i in range(n):
        ans += x[i] * y[n - i - 1]
    print(f'Case #{tcase}: {ans}')
