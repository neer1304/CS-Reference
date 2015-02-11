#!usr/bin/python

def lastFirst(firstName, lastName):            #1 
    separator = ', '                           #2 
    result = lastName + separator + firstName  #3 
    return result                              #4 
    
print lastFirst('Benjamin', 'Franklin')        #5 
print lastFirst('Andrew', 'Harrington')        #6 

