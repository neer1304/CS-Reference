#!/usr/bin/perl

use warnings;
use strict;

my @planets = ("mercury", "mars", "earth", "saturn", "pluto", "homeland");

print "------------------\n";
print "Postive indexes\n";
print "\@planets = (\"mercury\", \"mars\", \"earth\", \"saturn\", \"pluto\", \"homeland\")";
print "\n------------------\n";

my $count = "-1";
foreach (@planets) 
{
 $count++;
 print "index[$count] = $_\n";
} 

print "\n\n";
print "------------------\n";
print "Negative indexes\n";
print "\@planets = (\"mercury\", \"mars\", \"earth\", \"saturn\", \"pluto\", \"homeland\")";
print "\n------------------\n";

my $countback = "0";
foreach (reverse @planets) 
{
 $countback--;
 print "index[$countback] = $_\n";
}


