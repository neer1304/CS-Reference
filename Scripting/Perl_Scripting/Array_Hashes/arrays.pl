#!/usr/bin/perl
use warnings;
use strict;


my @months = ();  #Empty list

$" = ",";
@months = ("Jan", "Feb", "Mar"); #Array of 3 elements
#Index is   0       1      2
#Indexed by numbers

print "$months[0]", "\n";

print "$months[2]", "\n";

print "$months[-1]", "\n"; #prints last element

print "$months[-2]", "\n"; #prints second element from the last


print "Array months : @months \n";

print "Size of an array :", scalar @months, " \n";

print "Highest index of an array :", $#months, " \n";


my $l = @months;
print "Size of an array :", $l, " \n";


my @temp = @months; #Copy an array to another
print "Array temp :" , @temp;

=begin

A list or array is a series of scalars

Each piece of data in the list is an "element"

Array name starts with "@" sign

Naming conventions of scalars will apply for list/array also 




=cut

