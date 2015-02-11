#!/usr/bin/python
s='adamantium'
print 'String before function call: ',s

def attempt(t):
	t='helium'; return t #String immutable
back=attempt(s)

print 'function returned ',back
print 'String after function call: ',s

nums=[2,635.8,'eight',44,12.34]
print 'List before function call: ',nums
def morph(vector):
	vector[2]=8; return vector #List mutable
back=morph(nums)

print 'function returned ',back
print 'List after function call: ',nums
