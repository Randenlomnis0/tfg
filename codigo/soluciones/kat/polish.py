def isinteger(s):
    try:
        int(s)
        return True
    except:
        return False
tcase = 1
while True:
    try:
        tokens = input().split()
        s = []
        for token in tokens:
            s.append(token)
            while len(s) >= 3 and isinteger(s[-1]) and isinteger(s[-2]) and s[-3] in ['+', '-', '*']:
                if s[-3] == '+':
                    ans = int(s[-2]) + int(s[-1])
                elif s[-3] == '-':
                    ans = int(s[-2]) - int(s[-1])
                else:
                    ans = int(s[-2]) * int(s[-1])
                s.pop()
                s.pop()
                s.pop()
                s.append(str(ans))
        print(f'Case {tcase}:', end='')
        tcase += 1
        for x in s:
            print(f' {x}', end='')
        print()
    except EOFError:
        break
