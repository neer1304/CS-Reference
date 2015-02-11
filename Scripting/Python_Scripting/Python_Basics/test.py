numbers = []
not_numbers = []

for s in ['12', '-4.1', '1.0e2', 'e3']:
    try:
        n = float(s)
        numbers.append(s)
    except ValueError, msg:
        not_numbers.append(str(msg))

print 'numbers:', numbers
print 'not numbers:', not_numbers

