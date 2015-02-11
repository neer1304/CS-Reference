#!/usr/bin/perl
#use warnings;
#use strict;

$_ = "Nobody wants to hurt you... I do hurt people sometimes. Case.";


if ($_ =~ /case/i) {

	print "case is found \n";
}



if (s/hurt/HURT/g) {
	print "\$_ : $_ \n";
}

