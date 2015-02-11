#!/usr/bin/perl
use warnings;
use strict;

open FILE, "example.txt" or die $!;

my @a = <FILE>;

print "FILE : \n @a \n";

close FILE;


