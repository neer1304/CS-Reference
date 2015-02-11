#!/usr/bin/perl
use warnings;
use strict;

my ($a, $b);

$b = 10;

print $a, "\n";
print $b, "\n";


if (defined $a) {

	print "\$a has a value.\n";

}

undef $b;
$a = 20;
print $a, "\n";
print $b, "\n";

if (defined $b) {

	print "\$b has a value.\n";

}
















