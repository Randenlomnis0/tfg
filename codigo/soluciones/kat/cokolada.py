import math
def solve(N, K):
    if N == K:
        return 0
    if N // 2 >= K:
        return 1 + solve(N // 2, K)
    else:
        return 1 + solve(N // 2, K - N // 2)
K = int(input())
ans = 2**math.ceil(math.log2(K))
print(ans, solve(ans, K))
