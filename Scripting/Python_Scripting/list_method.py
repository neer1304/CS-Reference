r = [1, 2.0, 3, 5]
r.append('thing')              # add a single item to the end
print r
r.append(['another', 'list'])  # list treated as a single item
print r
r = [1, 2.0, 3, 5]
r.extend(['item', 'another'])  # list items appended one by one
print r
k = r.pop()                    # remove last item from list and return
print k
print r
r = [2, 5, -1, 0, 20]
r.sort()                        
print r
w = ['apa', '1', '2', '1234']
w.sort()                       # strings: lexical sort using ASCII order
print w
w.reverse()                    # how to flip a list; in-place!
print w
v = w[:]                       # first create a copy of the list
v.reverse()                    # then reverse the copy
print v                              # use same technique for sort
print w

