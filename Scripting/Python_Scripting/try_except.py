numbers = []
not_numbers = []
n=19
for s in [1,2,3,4,5,0]:
    try:
        a = n/s
        numbers.append(a)
    except ValueError, msg:
        not_numbers.append(str(msg))

print 'numbers:', numbers
print 'not numbers:', not_numbers

