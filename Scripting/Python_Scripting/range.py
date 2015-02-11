print range(9)                     # start=0, step=1 by default
print range(1, 12, 3)              # explicit start, end, step
#print range(10**9)                 # MemoryError!
s = 0
for i in xrange(100000):
    if (i % 19 == 0):              # remainder: evenly divisible with 19?
        s = s + i

print s

