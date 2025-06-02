n1 = int(input())
n2 = int(input())
dir = 1
if n1 > n2:
    n1, n2 = n2, n1
    dir *= -1
ans = (n2 - n1)%360
if ans > 180:
    ans = 360 - ans
    dir *= -1
elif ans == 180 and dir == -1:
    dir *= -1
print(ans * dir)
