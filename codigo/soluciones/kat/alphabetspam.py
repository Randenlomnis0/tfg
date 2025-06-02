s = list(input())
a = 0
b = 0
c = 0
d = 0
for x in s:
    if x == '_':
        a += 1
    elif 'a' <= x <= 'z':
        b += 1
    elif 'A' <= x <= 'Z':
        c += 1
    else:
        d += 1
print(f'{a / len(s):.6f}')
print(f'{b / len(s):.6f}')
print(f'{c / len(s):.6f}')
print(f'{d / len(s):.6f}')
