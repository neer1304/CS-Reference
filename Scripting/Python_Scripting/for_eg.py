s = 0
for i in [0, 1, 2, 3, 4, 5, 6, 7, 8]:     # walk through list, assign to i
    s = s + i
    if s > 10:
        break                             # quit 'for' loop, jump to after it

print "i=%i, s=%i" % (i, s)

