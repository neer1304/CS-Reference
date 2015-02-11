#!/usr/bin/perl
use warnings;
use strict;

print "Enter ten names \n";
my ($name, $i);



for ($i = 1; $i <= 10; $i++) 
{
	print "Enter name : ";	
	$name = <STDIN>;
	chomp($name);
	if ($name eq "Anu") 
	{
		next;
	}
	print "name : $name \n";
}

