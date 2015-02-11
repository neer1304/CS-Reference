#!/usr/bin/perl

use warnings;
use strict;

my $name;

print "$name", "\n";

$name = "Arizona";

print "Name : ", "$name", "\n";

$name = 99;

print "$name", "\n";

undef $name;
$name = 20;
print "$name", "\n";


=begin

- scalar variable is used to store strings and numbers

- perl will automatically do the necessary data conversions according
to the context

- case sensitive

- starts with "$" sign and the next character must be a letter or an underscore

- up to a total of 251 characters

- limited by the size of computers memory

=cut

