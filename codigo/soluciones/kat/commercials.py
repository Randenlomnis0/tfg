N, P = list(map(int, input().split()))
ans = 0
aux = 0
V = list(map(int, input().split()))
for n in V:
    aux += n - P
    ans = max(ans, aux)
    aux = max(aux, 0)
print(ans)
