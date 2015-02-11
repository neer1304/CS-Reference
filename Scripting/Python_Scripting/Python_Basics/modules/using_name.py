#!/usr/bin/python
# Filename: using_name.py
if __name__ == '__main__':
	print 'This program is being run by itself'
else:
	print 'I am being imported from another module'


#run as

#$ python using_name.py
#This program is being run by itself
#$ python
#>>> import using_name
#I am being imported from another module
#>>>
