#!/usr/bin/perl
use strict;
use warnings;
use subs qw/version/;


open FH, "example.txt" or die "$!";
my $file_ref = \*FH;
print "Type of reference :", ref($file_ref), "\n";

*NEW = *{$file_ref};
while(<NEW>) {
	print "$_";
}

close(FH);

