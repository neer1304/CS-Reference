#!/usr/bin/perl
use warnings;
use strict;


my @unsorted = qw/1 2 11 24 3 36 40 4/;

my $str = join(":", @unsorted); # Join the elements of the list with ":"

print "str : $str \n"; 


my @list = split(":", $str);

print "list : @list \n"; 



