#script to find sum of the digits of a number supplied as command line args. 

my $returnval;
$nargs = @ARGV;
print "The number of args = $nargs\n";


if ($nargs > 0)
{

	$returnval = sumdigit(@ARGV);

	print "The sum of the digits of $ARVG[0] is $returnval\n";
}
else
{
	print "Pl. supply at least one argument\n"
}



sub sumdigit()
{
	
	#Store Argument in the local variable
	#Ignore any other arguments which migt be in the array
	
	$dividend = $_[0];
	$digitsum = 0;

	while ($dividend)
	{
		$rem = $dividend % 10;
		$dividend = $dividend / 10;
		$digitsum = $digitsum + $rem ;
	}
	return $digitsum;
	
}

