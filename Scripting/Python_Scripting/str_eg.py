a = "Part 1"
b = "and part 2"
print a + ' ' + b           # concatenation, adding strings
s = a * 2 	            # repeat and concatenate string
print s
print s[0]                  # index: one single character, offset 0 (zero)
print s[0:4]                # slice: part of string
print s[5:]                 # leave out one boundary: to the end
print s[6:-1]               # negative index counts from the end
print len(s)                # function len to get length of string
print 'p' in s              # membership test
print 'P' in s
print 'Part' in s           # also works for substrings (new feature)
s = 'a string, with stuff'
print s.count('st')         # how many substrings?
print s.find('stu')         # give location of substring, if any
three = '3'
print three.isdigit()       # only digit characters in string?
supper = s.upper()          # convert to upper case
print supper
print s.rjust(30)                  	  # right justify by adding blanks
print "newlines\n\n\n".strip()      	 # a string literal also has methods!
print s.replace('stuff', 'characters') 	# replace substring (all occurrences)
print s.replace('s', 'X', 1)      	   # replace only once
cheer="Happy Holidays!"; print cheer
 # cheer[6]=B				 #Cannot do
print cheer[6:11]
 # cheer[6:11]="Birth" 			 #Still cannot do
cheer=cheer[0:6] + "Birthday" + cheer[-1]
print cheer

