#!/usr/bin/perl 

use warnings;
use strict;

my @planets1 = ("mercury", "mars", "earth", "saturn", "pluto", "homeland");
my @planets2 = ("mercury", "mars", "earth", "saturn", "pluto", "homeland");
my @planets3 = ("mercury", "mars", "earth", "saturn", "pluto", "homeland");
my @planets4 = ("mercury", "mars", "earth", "saturn", "pluto", "homeland");
my $elements = "mercury mars earth saturn pluto homeland";

print "-------------------\n";
print "Before:\n";
print " $elements\n";
print "Effect:\n";
print " POP\n";
print "Results:\n";

pop(@planets1);

print " ";
print join(" ", @planets1);

print "\n-------------------\n\n\n";


print "-------------------\n";
print "Before:\n";
print " $elements\n";
print "Effect:\n";
print " PUSH push(\@array, \"jupiter\")\n";
print "Results:\n";

push(@planets2, "jupiter");

print " ";
print join(" ", @planets2);
print "\n-------------------\n\n\n";

 

print "\n-------------------\n";
print "Before:\n";
print " $elements\n";
print "Effect:\n";
print " SHIFT\n";
print "Results:\n";

shift(@planets4);

print " ";
print join(" ", @planets4);
print "\n-------------------\n\n\n";


print "\n-------------------\n";
print "Before:\n";
print " $elements\n";
print "Effect:\n";
print " UNSHIFT unshift(\@array, \"sun\")\n";
print "Results:\n";

unshift(@planets3, "sun");

print " ";
print join(" ", @planets3);
print "\n-------------------\n\n\n";


