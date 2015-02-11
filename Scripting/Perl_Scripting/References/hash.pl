#!/usr/bin/perl
use strict;
use warnings;

my %players= qw/cricket sachin tennis federer golf woods/;
my $hash_ref = \%players;

print "Type of reference: ", ref($hash_ref), "\n";
print "Value pointed by the ref : ",  %{$hash_ref}, "\n";
print "Third element of the hash : ", ${$hash_ref}{tennis}, "\n";
print "Third element of the hash : ", $hash_ref->{tennis}, "\n";





