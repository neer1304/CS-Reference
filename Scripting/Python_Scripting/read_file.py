f = open('test.txt')      # by default: read-only mode
#line = f.readline()       # read a single line
#print line
#lines = f.readlines()     # read all remaining lines
#print lines

import re

for line in f:
	zinc_finger = re.compile('C.C..H..H')    # compile regular expression pattern
	a=zinc_finger.findall(line)
	s=''.join(a)
	if( len(s)>0):
		print line

