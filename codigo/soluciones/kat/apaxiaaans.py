s = list(input())
ans = s[0]
for i in range(1, len(s)):
    if s[i] == s[i - 1]:
        continue
    ans += s[i]
print(ans)
