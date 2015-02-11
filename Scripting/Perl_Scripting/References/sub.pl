#!/usr/bin/perl
use strict;
use warnings;
use subs qw/version/;

my $sub_ref = \&version;
print "Type of reference: ", ref($sub_ref), "\n";

#&$sub_ref();
$sub_ref->();




sub version {
	print "version 1.0", "\n";
}


