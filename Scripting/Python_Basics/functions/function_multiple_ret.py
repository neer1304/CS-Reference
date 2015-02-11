#!/usr/bin/python
def more(s1,s2,s3='sil'):
	S=[s1+s2,s2+s3]
	L=[len(s1+s2),len(s1+s2)]
	return(S,L) #Two-tuplereturned
Merge,Length=more('pro','ton') #Two Lists receive
print "Merge list= ",Merge
print "Length list=",Length
