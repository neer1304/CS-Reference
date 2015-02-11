#!/usr/local/bin/perl
#
# Program to read and print a file 
#
open(ALICE, "alice.txt");
@lines = <ALICE> ;
close(ALICE);
print @lines;


=begin

1. Modify the program so that the lines are printed in reverse order.

2. Modify the program so that each line is printed with a line number at the 
   beginning. (Hint: use a foreach loop and a counter.)

=cut

