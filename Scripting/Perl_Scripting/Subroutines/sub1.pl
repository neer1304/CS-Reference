#!/usr/bin/perl
use warnings;
use strict;


sub version() {

	print "Version 1.0", "\n";

}

version;



=begin

# Declare the subroutine

use subs qw/version/;
sub version;

# Different ways of calling a subroutine

version();
&version();
&version;
version;

=cut

