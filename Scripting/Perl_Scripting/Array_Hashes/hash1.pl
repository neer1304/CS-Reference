#!/usr/bin/perl
use warnings;
use strict;

my %where=(
        Anu     => "Hyderabad",
        Dinesh  => "Chennai",
        Suri    => "Bangalore",
        Sreenu => "Mumbai",
	Mohan => "Delhi"
);




my @keyList = keys %where;

my @valList = values %where;

print "keys : @keyList \n";


print "values : @valList \n";


my ($key, $value) = each %where;

my ($key1, $value1) = each %where;
my ($key2, $value2) = each %where;
my ($key3, $value3) = each %where;


print "Key : $key Val : $value \n";

print "Key : $key1 Val : $value1 \n";
print "Key : $key2 Val : $value2 \n";
print "Key : $key3 Val : $value3 \n";

print %where, "\n";





