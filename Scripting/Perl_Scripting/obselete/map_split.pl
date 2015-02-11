#!usr/bin/perl
use strict;
use warnings;
my @arr = ( "I","S","H","E","R","E");
 
print(map lc,"H","E","L","L" ."\n"); # output is hell . But how this differs from the next statement?

print((map lc,"H","E","L","L") . "\n");#returns 4 is bcoz print treat the list returnd by map as string and concatenates? 

#Sibu: Here map function is in scalar context. So it returns the number list 
#elements it has processed. It is 4. "\n" is not getting concatenated. I am not
#sure why map function is in scalar context here.

print ((split//,(map lc,"H","E","L","L",@arr) ."\n"));    #split is used to seperate string into list and so this will not work 
 
#as map already returns a list and so here split takes it as 10, which is the count of list items that it got from map to split. so can we
# conclude that split is of no use when used with map?

#Sibu: We can not conclude that split is of no use when used with map. This 
# happens only becuase map is in scalar context. If map is in list context, 
# then split could be used.


print ((split//,(map lc,"H","E","L","L",@arr)) ."\n"); # output is 1. How / why?

#Sibu: I got the output as 2, not as 1. There is also a warning. 
 
print ((split",","h,e,l,l,o\n")[0] ,"\n"); #splits the string @ each occurence of the pattern and so [0] refers h and output is h

#Sibu: Correct
 
print(split"","h,e,l,l,o" ."\n"); #Since . is used here is the list returned by split in this case it is h,e,l,l,o is considered as a string by the print function and then concatenates and prints h,e,l,l,o? 

#Sibu: There is a concatenation which takes place. Since we can not print 
#individual characters using array index , we could say that concatenation takes
#place after split. Then h,e,l,l,o has to be considered as a string.
 
# Also how to know which is [0] in this case ,bcoz if i give [0] in the statement , the output will be simply h and so in my assumption here the entire h,e,l,l,o is [0] bcoz . is used for concatenation of strings. Is this rite?
 
#Sibu: We can not use [0] here becuase it is no more an array or list. It is 
#just a string. Please remember scalar strings.

print((split"","h,e,l,l,o,w,o,r,l,d")[2]."\n"); # output is e. Please consider this output also as an example for providing the solution of my above question. 

#Sibu: Since we are using array index operator before concatenation, there are
# no issues. "\n" is concatenated to scalar string "e". 

# as i said above , if i didn't specify [2] , it will display h,e,l,l,o,w,o,r,l,d and so here whether this  whole h,e,l,l,o,w,o,r,l,d is 
# considered as a string ?and then concatenation done

#Sibu: If we do not use [2], will it print h,e,l,l,o,w,o,r,l,d? It prints 19.
