N = int(input())
H = list(map(int, input().split()))
mx = max(H)
arrow = [0 for _ in range(mx + 1)]
ans = 0
for x in H:
    if arrow[x] == 0:
        ans += 1
    else:
        arrow[x] -= 1
    arrow[x - 1] += 1
print(ans)
