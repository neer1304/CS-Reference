#!/usr/bin/perl
use warnings;
use strict;


my @months;

@months = ("Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec");


print "@months \n";


print "@months[3..9] \n";

my @revmonths = reverse(@months);


print "Months in reverse order @revmonths \n"; 

my @sorted = sort @months;

print "Months in sorted @sorted \n"; 


=begin
@months = qw/Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec/;




=cut

