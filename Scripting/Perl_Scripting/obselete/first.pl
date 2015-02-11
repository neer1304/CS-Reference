#!/usr/bin/perl

use strict; 	# important pragma
use warnings; 	# another important pragma

print "What is your username? "; 	# print out the question
my $username; 		# "declare" the variable

$username = <STDIN>; 	# ask for the username

chomp($username); 	# remove "new line"

print "Hello, $username.\n"; 	# print out the greeting


# Now we have said hello to our user
