#!/usr/bin/perl
use warnings;
use strict;

my $place = "Hyderabad";
my %where=(
        Anu     => "Hyderabad",
        Dinesh  => "Bangalore",
        Suri    => "Bangalore",
        Sreenu => "Mumbai"
	
);

#print %where;
my @allkeys;
@allkeys = keys(%where);

print "The keys are @allkeys\n";



print "Anu lives in ", $where{Anu}, "\n";

print "Dinesh lives in $where{Dinesh}\n";



$where{Khaja} = "Delhi";


print "Khaja lives in $where{Khaja}\n";
@allkeys = keys(%where);

print "The keys are @allkeys\n";
