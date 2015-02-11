#!/usr/bin/perl
use warnings;
use strict;


my @months;

@months = ("Jan", "Feb", "Mar");

# To add elements from the right end
# Using push we can add list of elements
 
push @months, "Apr", "May";

print "months : @months \n"; # Jan Feb Mar Apr May

# To remove elements from the right end
# pop will remove one element from the right end 

pop @months; 

print "months : @months \n"; # Jan Feb Mar Apr

