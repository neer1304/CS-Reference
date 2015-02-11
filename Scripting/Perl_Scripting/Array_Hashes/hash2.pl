#!/usr/bin/perl  
# define hash  
%matrix = (	"hero" => "neo", 
		"villain" => "smith", 
		"teacher" => "morpheus", 
		"babe" => "trinity");  

delete ($matrix{"villain"}); 

print "%matrix";

=begin
foreach $k (keys(%matrix))  
{  
        delete ($matrix{$k});  
} 
=cut

