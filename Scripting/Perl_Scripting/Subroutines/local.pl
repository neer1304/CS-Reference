#!/usr/bin/perl
#use warnings;
#use strict;

my $a = 510;

first();
third();

sub first 
{
	my $b = 10;	
	second();
	print "In first : $b \n";
}

sub second 
{
	print "In second : $b \n";
}

sub third 
{
	print "In third : $b \n";
}

