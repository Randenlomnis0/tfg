m = int(input())
for _ in range(m):
    X, Y = list(map(float, input().split()))
    n = int(input())
    cursethedarkness = True
    for _ in range(n):
        x, y = list(map(float, input().split()))
        x -= X
        y -= Y
        if x**2 + y**2 > 64.0:
            continue
        cursethedarkness = False
    print("curse the darkness" if cursethedarkness else "light a candle")
