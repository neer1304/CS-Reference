#!/usr/bin/perl
use warnings;
use strict;


#my @a = (1, 2, 11, 24, 3, 36, 40, 4);

my @a = (1, 2, "a", 24, "xy", 36, 40, 100);

my @b = sort @a;

print "Sorted array : @a \n";#1 11 2 24 3 36 4 40

@b = sort {$a <=> $b} @a;

print "Sorted array : @b \n";#1 2 3 4 11 24 36 40

@b = sort {$b <=> $a} @a;

print "Sorted array : @b \n";#40 36 24 11 4 3 2 1






