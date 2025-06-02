N = int(input())
preferences = [tuple(map(int, input().split())) for _ in range(N)]
preferences.sort()
ans = 0
aux = 0
for preference in preferences:
    if aux < preference[0]:
        ans += 1
        aux = preference[1]
    else:
        aux = min(aux, preference[1])
print(ans)
