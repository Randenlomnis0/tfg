pword, msg = input().split()
j = 0
passd = True
for i in range(len(pword)):
    if not passd:
        break
    found = False
    while j < len(msg) and pword[i] != msg[j]:
        for k in range(i + 1, len(pword)):
            if pword[k] != msg[j]:
                continue
            passd = False
            break
        j += 1
    if j < len(msg):
        found = True
        j += 1
    if not found:
        passd = False
print("PASS" if passd else "FAIL")
