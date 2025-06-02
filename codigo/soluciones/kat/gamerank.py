def starts(lvl):
    if lvl > 20:
        return 2
    if lvl > 15:
        return 3
    if lvl > 10:
        return 4
    return 5
s = list(input())
stars, lvl, wstreak = 0, 25, 0
for c in s:
    if lvl == 0:
        break
    if c == 'W':
        wstreak += 1
        if lvl > 5 and wstreak >= 3:
            stars += 2
        else:
            stars += 1
        if lvl != 0 and stars > starts(lvl):
            stars -= starts(lvl)
            lvl -= 1
    else:
        wstreak = 0
        if lvl <= 20:
            stars -= 1
        if lvl >= 20:
            stars = max(stars, 0)
        if stars < 0:
            lvl += 1
            stars = starts(lvl) - 1
if lvl == 0:
    print("Legend")
else:
    print(lvl)
