#!/usr/bin/perl
use warnings;
use strict;

#Adding prototype for a subroutine
sub add($$);

#Declaring a variable
my $sum;

$sum = add (3, 5);
print "Sum of 3 and 5 is : ", $sum, "\n";


#Defining a subroutine add
sub add() 
{
	my ($a, $b) = (shift, shift);
	($a + $b);
}


=begin

Parameters passed to a subroutine can be accessed in a subroutine using 

a special variable @_ (It is an array)


To declare two variables in a single statement

my ($a, $b);


#return ($a + $b);


=cut

