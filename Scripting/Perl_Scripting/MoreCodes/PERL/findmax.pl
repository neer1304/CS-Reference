#script to find maximum of a series of numbers supplied as command line args

my $returnval;

#my @array = (1, 199, 77);

#$returnval = &maxfinder(1009, 2, 3 , 8888 , 77,77, 66, 0, 55, 44444);

if ( $#ARGV > 0)
{

	$returnval = maxfinder(@ARGV);


	print "The maximum value is $returnval";
}
else
{
	print "Pl. supply at least one argument\n"
}



sub maxfinder()
{
	
	#Flat list of arguments is @_
	
	my @arguments = @_; #Since, by default Call by ref
			# better to copy the args locally
	
	my $max = shift(@arguments);#Setting max to the first argument
	
	foreach $var (@arguments)
	{
		if ( $max < $var)
		{
			$max = $var;
		}
	}
	return $max;
}

