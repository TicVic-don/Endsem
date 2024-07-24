def minint(a):
    e = []
    o = []

    for digit_char in a:
        digit = int(digit_char)
        if digit % 2 == 0:
            e.append(digit)
        else:
            o.append(digit)

    res = ""
    eidx, oidx = 0, 0

    while eidx < len(e) and oidx < len(o):
        if e[eidx] < o[oidx]:
            res += str(e[eidx])
            eidx += 1
        else:
            res += str(o[oidx])
            oidx += 1

    while eidx < len(e):
        res += str(e[eidx])
        eidx += 1
    while oidx < len(o):
        res += str(o[oidx])
        oidx += 1

    return res

t = int(input())
for i in range(t):
    s = input()
    print(minint(s))
