r = []
n = 0
last = 20

while n <= last:           # any expression interpretable as Boolean
    r.append(str(n))
    n += 3

print ', '.join(r)

