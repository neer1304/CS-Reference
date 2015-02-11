#!/usr/bin/perl
use strict;
use warnings;

my $a = "Bangalore";
my $scalar_ref = \$a;
my $scalar_ref1 = \$scalar_ref;

print "\$scalar_ref :", $scalar_ref, "\n";
print "Type of reference : ", ref($scalar_ref), "\n";
print "Value pointed by scalar_ref is : ", ${$scalar_ref}, "\n";

print "\$scalar_ref1 :", $scalar_ref1, "\n";
print "Type of reference : ", ref($scalar_ref1), "\n";
print "Value pointed by scalar_ref is : ", ${${$scalar_ref1}}, "\n";

