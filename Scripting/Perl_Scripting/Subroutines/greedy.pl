#!/usr/bin/perl
use warnings;
use strict;

my (@a, @b, @c, @d, @y);
my ($x, $y);

@a = qw/1 2 3  4 5/;
@b = qw/6 7 8 9 10/;

($x, $y) = (@a);
print "x : $x y : $y \n";

($x, @y) = @a;
print "x : $x y : @y \n";

(@y, $x) = @a;
print "x : $x y : @y \n";


(@c, @d) = (@a, @b);

print "list c : @c \n";
print "list d : @d \n";

