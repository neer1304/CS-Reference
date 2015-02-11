#!/usr/bin/python
def integral(begin,end,acc):
	print 'begin= ', begin
	print 'end= ', end
	print 'acc= ', acc
	return

integral(5.0,25.0,0.001) #Positional Matching
integral(acc=0.001,end=55.0,begin=10.0) #Keyword Matching
integral(6.0,acc=0.001,end=38.0) #Combination
