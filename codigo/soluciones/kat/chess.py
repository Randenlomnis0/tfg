itos = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
def samediag(a, b, c, d):
    return a - b == c - d or a + b == c + d
t = int(input())
for _ in range(t):
    A, B, C, D = input().split()
    a = ord(A) - ord('A') + 1
    b = int(B)
    c = ord(C) - ord('A') + 1
    d = int(D)
    if (a + b + c + d)%2:
        print("Impossible")
    elif a == c and b == d:
        print(0, A, B)
    elif samediag(a, b, c, d):
        print(1, A, B, C, D)
    else:
        p = -1
        q = -1
        for i in range(1, 9):
            for j in range(1, 9):
                if not samediag(a, b, i, j) or not samediag(c, d, i, j):
                    continue
                p = i
                q = j
        print(2, A, B, itos[p - 1], q, C, D)
