#!/usr/bin/python
def integral(begin=1.0,end=500.0,acc=0.001):
	print 'begin=', begin,'end=',end,'acc=',acc
	return
integral(5.0,25.0,0.0000001) #No defaults used
integral(3.0,18.0) #1 default used
integral(5.0) #2 defaults used
integral() #All defaults used
#integral(,333.0,) #ILLEGAL
