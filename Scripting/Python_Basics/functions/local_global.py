x = 6
print 'outside x before call: ',x
def gsum(y,z):
	global x #Changing a global variable
	x=y+z; return x
back=gsum(22,8)
print "Global sum= ",back
print 'outside x after call: ',x

def lsum(y,z):
	x=y+z; return x #Using just local variables
back=lsum(4,8)

print "Local sum= ",back
a=33
print 'outside a before call: ',a

def nsum(y,z):
	a=y+z; return a #Using a global variable name
back=nsum(5,6)
print "No sum= ",back
print 'outside a after call: ',a
