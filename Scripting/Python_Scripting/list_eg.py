r = [1, 2.0, 3, 5]       # list literal; different types of values
print r
print type(r)
print r[1]                     # access by index; offset 0 (zero)
print r[-1]                    # negative index counts from end
print r[1:3]                   # a slice out of a list; gives another list
w = r + [10, 19]         # concatenate lists; gives another list
print w
print r                        # original list unchanged; w and r are different
t = [0.0] * 10           # create an initial vector using repetition
print t
r = [1, 2.0, 3, 5]
r[3] = 'word'            # replace an item by index
print r
r[0] = [9, 8]            # lists can be nested
print r
r[0:3] = [1, 2, 5, 6]    # change a slice of list; may change list length
print r
r[1:3] = []              # remove items by setting slice to empty list
print r
print len(r)                   # length of list; number of items
print 6 in r                   # membership test
print r.index(6)               # search for position; bombs if item not in list

