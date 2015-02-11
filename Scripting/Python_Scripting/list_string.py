s = 'biovitrum'                            # create a string
w = list(s)                                # convert into a list of char's
print w
w.reverse()
print w
r = ''.join(w)                             # join using empty string
print r
d = '-'.join(w)                            # join using dash char
print d
s = 'a few words'
w = s.split()               # splits at white-space (blank, newline)
print w
print ' | '.join(w)
