def calc(flies, i, j, K):
    return flies[i][j] - flies[i - K][j] - flies[i][j - K] + flies[i - K][j - K]
R, S, K = list(map(int, input().split()))
picture = [list(input()) for _ in range(R)]
flies = [[0 for _ in range(S)] for _ in range(R)]
for i in range(R):
    for j in range(S):
        if i > 0:
            flies[i][j] += flies[i - 1][j]
        if j > 0:
            flies[i][j] += flies[i][j - 1]
        if i > 0 and j > 0:
            flies[i][j] -= flies[i - 1][j - 1]
        if picture[i][j] == '*':
            flies[i][j] += 1
ans = -1
ansi = -1
ansj = -1
for i in range(K - 1, R):
    for j in range(K - 1, S):
        aux = calc(flies, i - 1, j - 1, K - 2)
        if aux > ans:
            ans = aux
            ansi = i
            ansj = j
print(ans)
for i in range(K):
    picture[ansi - i][ansj] = '|'
    picture[ansi - i][ansj - K + 1] = '|'
    picture[ansi][ansj - i] = '-'
    picture[ansi - K + 1][ansj - i] = '-'
picture[ansi - K + 1][ansj - K + 1] = '+'
picture[ansi - K + 1][ansj] = '+'
picture[ansi][ansj - K + 1] = '+'
picture[ansi][ansj] = '+'
for row in picture:
    for x in row:
        print(x, end='')
    print()
