k = int(input())
for _ in range(k):
    n = int(input())
    goal = 1
    ids = list(map(int, input().split()))
    for id in ids:
        if id != goal:
            continue
        goal += 1
    print(n - goal + 1)
