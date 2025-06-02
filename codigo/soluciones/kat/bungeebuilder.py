N = int(input())
tallest = -1
smallest = -1
ans = 0
V = list(map(int, input().split()))
for x in V:
    if tallest != -1:
        if smallest != -1:
            ans = max(ans, min(x, tallest) - smallest)
            smallest = min(smallest, x)
        else:
            smallest = x
        if x > tallest:
            tallest = x
            smallest = -1
    else:
        tallest = x
print(ans)
