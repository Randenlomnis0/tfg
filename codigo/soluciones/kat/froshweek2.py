n, m = list(map(int, input().split()))
tasks = list(map(int, input().split()))
tasks.sort()
intervals = list(map(int, input().split()))
intervals.sort()
ans = 0
j = 0
for i in range(n):
    while j < m and intervals[j] < tasks[i]:
        j += 1
    if j < m:
        ans += 1
        j += 1
print(ans)
