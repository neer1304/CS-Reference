#!/usr/bin/perl
use warnings;
use strict;

print "Enter ten names \n";
my ($name, $i);

$i = 1;

for (; $i <= 10; $i++) 
{
	print "Enter name : ";	
	$name = <STDIN>;
	chomp($name);
	if ($name eq "Anu") 
	{
		print "Found Anu \n";
		last;
	}
	print "name : $name \n";
}

