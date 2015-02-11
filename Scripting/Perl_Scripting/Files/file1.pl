#!/usr/bin/perl
use warnings;
use strict;

open FILE, "example.txt" or die $!;

my $lineno = 1;

my $var;

while ($var = <FILE>) 
{
	print "$lineno: ","$var";
	$lineno++;
#	print $., ": $_";

}


close FILE;


=begin

- Opening a file in read mode
	
	open FH, "example.txt";
	
	open FH, "<example.txt";


- Opening a file in write mode

	open FH, ">example.txt";

- Opening a file in append mode

	open FH, ">>example.txt";



while (<FILE>)  =>  while (defined ($_ = <FILE>))

=cut

