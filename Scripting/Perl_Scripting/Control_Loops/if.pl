#!/usr/bin/perl
use warnings;
use strict;


print "Enter a number : ";

my $num = <STDIN>;

chomp($num);


if ($num > 10 ) {

	print "Number is greater than 10 \n";


} else {

	print "Number is less than 10 \n";

} 

