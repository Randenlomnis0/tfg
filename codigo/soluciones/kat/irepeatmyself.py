def probar(s1, s2):
    for i in range(len(s2)):
        if s2[i] != s1[i%len(s1)]:
            return False
    return True
n = int(input())
for _ in range(n):
    line = list(input())
    for i in range(1, len(line) + 1):
        if not probar(line[0:i], line):
            continue
        print(i)
        break
