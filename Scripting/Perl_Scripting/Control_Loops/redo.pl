#!/usr/bin/perl
use warnings;
use strict;

print "Enter three names \n";
my ($name, $i);


for ($i = 1; $i <= 3; $i++) 
{
	print "Enter name : ";	
	$name = <STDIN>;
	chomp($name);
	unless (length($name)) 
	{
		redo;
	}
	print "name : $name \n";
}

