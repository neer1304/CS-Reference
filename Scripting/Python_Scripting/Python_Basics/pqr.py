r = [1, 3, -10, 98, 2, 48]

for i in r:
    if i < 0:
        print 'input contains negative value!'
        break                   # this skips out of loop, including 'else'
    else:
        pass                    # do-nothing statement
else:                           # do if loop ended normally
    print 'input is OK'

