r, n = list(map(int, input().split()))
booked = [False for _ in range(r)]
for _ in range(n):
    x = int(input())
    booked[x - 1] = True
ans = False
for i in range(r):
    if booked[i]:
        continue
    print(i + 1)
    ans = True
    break
if not ans:
    print("too late")
