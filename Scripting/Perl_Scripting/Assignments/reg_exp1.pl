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
    if ($line =~/the /)
    {
        print $line;
    } # end of if 
} # end of foreach 


=begin

1. Retrieve all lines from alice.txt that do not contain /the /. Retrieve all 
   lines that contain "the" with lower or upper case letters.

2. Retrieve lines that contain a three letter string consisting of "t", then any   character, then "e", such as "the dog", "tree", "not ever". 

3. Retrieve lines that contain a word of any length that starts with t and ends    with e. Modify this so that the word has at least three characters.

4. Retrieve lines with a three letter word that starts with t and ends with e.

=cut
