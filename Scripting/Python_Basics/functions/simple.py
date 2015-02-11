#!/usr/bin/python
def scale_sum(x,y,z,factor): #Function Definition
	sum=x+y+z #Local variable
	res=factor*sum #Return value in local variable
	return res

out=scale_sum(4,2,9,5) #Call with ints
print "scale_sum returned",out
out=scale_sum(45.2,873.2,5.62,-0.01) #Call with floats
print "scale_sum returned",out
out=scale_sum('Hip ','Hip ','Horray',3) #Call with strings
print "scale_sum returned",out
