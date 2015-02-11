#!/usr/bin/perl
use warnings;
use strict;

my $x = 10;

my $ret = increment(\$x);
print "Value of ret is : ", $ret, "\n"; 
print "Value of x is : ", $x, "\n"; 


sub increment 
{
	my $y = shift;
	++${$y};	

	#print "${$y} \n";
}


