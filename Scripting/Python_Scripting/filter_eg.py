r = [0, 1, 2, 3, 4, 5, 6]
def large(x,y): return x>y
#print map(large,r)
#print filter(large,r)
print reduce(large,r)
