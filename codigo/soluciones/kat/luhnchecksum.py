T = int(input())
for _ in range(T):
    s = list(input())
    ans = 0
    for i in range(len(s)):
        if i%2:
            aux = 2 * (ord(s[- (i + 1)]) - ord('0'))
            if aux > 9:
                aux = aux // 10 + aux%10
            s[- (i + 1)] = chr(aux + ord('0'))
        ans += ord(s[- (i + 1)]) - ord('0')
    print("PASS" if ans%10 == 0 else "FAIL")
