def fun():
    lis = []
    i = 0
    while i < 3:
        lis.append(lambda x: print(i*x, end= ","))
        i += 1
    return lis
for f in fun():
    f(2)