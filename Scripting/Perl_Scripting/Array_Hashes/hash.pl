#!/usr/bin/perl
use warnings;
use strict;

my $place = "Hyderabad";
my %where=(
        Anu     => "Hyderabad",
        Dinesh  => "Bangalore",
        Suri    => "Bangalore",
        Sreenu => "Mumbai",
	Anu => "Gurgaon"
);

print %where, "\n";

my %who = reverse %where;

print %who, "\n";

print "Anu lives in ", $where{Anu}, "\n";

print "Dinesh lives in $where{Dinesh}\n";

print "$who{Bangalore} lives in Bangalore\n";

print "$who{$place} lives in $place\n";


$where{Khaja} = "Delhi";


print "Khaja lives in $where{Khaja}\n";

