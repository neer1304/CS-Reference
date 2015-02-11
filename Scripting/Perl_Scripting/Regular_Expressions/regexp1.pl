#!/usr/bin/perl
#use warnings;
#use strict;

$_ = "Nobody wants to hurt you...  I do hurt people sometimes. Case.";

my $found = 0;

my $sought = "people";

foreach my $word (split) 
{
	if ($word eq $sought) 
	{
		$found = 1;
		last;	
	}	
}


if ($found) 
{
	print "Horray! Found the word 'people` \n";
}

