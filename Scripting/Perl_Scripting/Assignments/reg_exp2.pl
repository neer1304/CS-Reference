#!/usr/local/bin/perl 
#
# Regular expressions 
#
# reading a file: 
open(ALICE, "alice.txt");
@lines = <ALICE> ;
close(ALICE);

# searching the file content line by line:
foreach $line (@lines)
{
 $line =~s/T/t/g;
 print $line;
} # end of foreach 

=begin

Using the alice.txt file replace 
 1. all upper case A by lower case a. 
 2. the word "Alice" by "ALICE".
 3. Delete all words with more than 3 characters.
 4. Print two blank space characters after the "." at the end of a sentence. 
 5. Replace single quotes (' or `) by double quotes. 

=cut


