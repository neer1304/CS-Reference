#!/usr/bin/perl
use strict;
use warnings;

my @a = qw/1 2 3 4 5 6/;
my $array_ref = \@a;

print "Type of reference: ", ref($array_ref), "\n";
print "Value pointed by the ref : ",  "@{$array_ref}", "\n";
print "Third element of the array : ", ${$array_ref}[2], "\n";
print "Third element of the array : ", $array_ref->[2], "\n";





