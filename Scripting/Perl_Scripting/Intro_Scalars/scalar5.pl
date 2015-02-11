#!/usr/bin/perl
use warnings;
use strict;


my $name = <STDIN>;

chomp($name);
chop($name);

print "***** name : $name ***** \n";

=begin

chop removes last character
chomp removes new line character


=cut

