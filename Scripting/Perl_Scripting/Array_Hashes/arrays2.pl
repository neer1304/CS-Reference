#!/usr/bin/perl
use warnings;
use strict;


my @months;

@months = ("Mar", "Apr", "May");

# To add elements from the left end
# Using unshift we can add list of elements
 
unshift @months, "Jan", "Feb";

print "months : @months \n"; # Jan Feb Mar Apr May

# To remove elements from the left end
# shift will remove one element from the left end 

shift @months; 

print "months : @months \n"; # Feb Mar Apr May

