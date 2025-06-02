n = int(input())
for _ in range(n):
    s, d = list(map(int, input().split()))
    if s < d or (s + d)%2 != 0:
        print("impossible")
    else:
        print((s + d) // 2, s - ((s + d) // 2))
