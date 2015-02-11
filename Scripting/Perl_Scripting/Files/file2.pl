#!/usr/bin/perl
use warnings;
use strict;


open RH, "example.txt" or die $!;

open WH, ">example1.txt" or die $!;

my $lineno = 1;

while (<RH>) {

	print WH "$_";

}


close RH;
close WH;

