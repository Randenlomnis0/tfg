while True:
    A = list(map(int, input().split()))
    n = A[0]
    if n == 0:
        break
    A.pop(0)
    LIS = [1 for _ in range(n)]
    p = [-1 for _ in range(n)]
    ans = 0
    for i in range(1, n):
        for j in range(i):
            if A[j] >= A[i]:
                continue
            if LIS[i] < LIS[j] + 1:
                LIS[i] = LIS[j] + 1
                p[i] = j
            elif LIS[i] == LIS[j] + 1 and A[j] < A[p[i]]:
                p[i] = j
        if LIS[i] > LIS[ans]:
            ans = i
        elif LIS[i] == LIS[ans] and A[i] < A[ans]:
            ans = i
    print(LIS[ans], end='')
    v = []
    while ans != -1:
        v.append(A[ans])
        ans = p[ans]
    v.reverse()
    for x in v:
        print('', x, end='')
    print()
