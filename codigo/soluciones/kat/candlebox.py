def isvalid(b, x):
    lb = 0
    hb = x
    while lb != hb - 1:
        nb = (lb + hb + 1) // 2
        if nb * (nb + 1) // 2 - b * (b + 1) // 2 >= x:
            hb = nb
        else:
            lb = nb
    return hb * (hb + 1) // 2 - b * (b + 1) // 2 == x
def age(b, x):
    lb = 0
    hb = x
    while lb != hb - 1:
        nb = (lb + hb + 1) // 2
        if nb * (nb + 1) // 2 - b * (b + 1) // 2 >= x:
            hb = nb
        else:
            lb = nb
    return hb
D = int(input())
R = int(input())
T = int(input())
for i in range(R):
    if isvalid(3, R - i) and isvalid(2, T + i) and abs(age(3, R - i) - age(2, T + i)) == D:
        print(i)
        break
