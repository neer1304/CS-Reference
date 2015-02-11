#!/usr/bin/python
dist=0;
steps=0;
while (abs(dist) != 3): #Entry Condition
	entry=raw_input('Flip a coin. Enter h or t: ')
	if (entry=='h'):
		dist += 1
		steps += 1
	elif(entry=='t'):
		dist -= 1
	steps += 1 #End of Loop Body
print 'You took %d steps' % steps
