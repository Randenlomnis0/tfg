T = int(input())
for tcase in range(1, T + 1):
    alien_number, source_language, target_language = [list(x) for x in input().split()]
    source_pos = {char: i for i, char in enumerate(source_language)}
    b10 = 0
    aux = 1
    base = len(source_language)
    for i in range(len(alien_number)):
        b10 += aux * source_pos[alien_number[-(i + 1)]]
        aux *= base
    base = len(target_language)
    ans = ''
    while b10 > 0:
        ans += target_language[b10%base]
        b10 //= base
    print(f'Case #{tcase}: {ans[::-1]}')
