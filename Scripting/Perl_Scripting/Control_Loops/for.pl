#!/usr/bin/perl
use warnings;
use strict;


my $i;


####

for ($i = 1; $i <= 10; $i++) {


	print "$i \t";


}

print "\n";

#### 
for $i (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) {


	print "$i \t";

}

print "\n";

#### 
my @a = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

for $i (@a) {

	print "$i \t";

}

print "\n";


####

foreach $i (@a) {

	print "$i \t";

}


print "\n";

####
for (@a) {

	print "$_ \t";

}

print "\n";



####
foreach (@a) {

	print "$_ \t";

}


print "\n";















