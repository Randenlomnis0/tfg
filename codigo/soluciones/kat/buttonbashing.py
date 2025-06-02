T = int(input())
for _ in range(T):
    n, t = list(map(int, input().split()))
    buttons = list(map(int, input().split()))
    ans = [-1 for _ in range(3601)]
    aux = 0
    q = []
    q.append(0)
    q.append(-1)
    while len(q) > 1:
        i = q.pop(0)
        if i == -1:
            aux += 1
            q.append(-1)
            continue
        if ans[i] != -1:
            continue
        ans[i] = aux
        for button in buttons:
            if ans[max(0, min(3600, i + button))] != -1:
                continue
            q.append(max(0, min(3600, i + button)))
    aux = t
    while ans[aux] == -1:
        aux += 1
    print(ans[aux], aux - t)