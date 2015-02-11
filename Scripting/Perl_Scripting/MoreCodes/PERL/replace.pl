#Reads a file(argv[0]),searches a string(argv[1])
#and replaces with a string(argv[2])


#Fetch Number of file From Cmd Line

$nargs = @ARGV;


#Report Error and exit for Improper Args
if ( $nargs < 3 )
{
	print " Pl. invoke as file <search> <replace>\n";
	die;
}


#Having two globals array(used to fetch the lines of a file), count(No of Lines)
my @array = ();
my $search = $ARGV[1];
my $replace = $ARGV[2];
print "$search $replace\n";
my $count;

#Opening  i/p file
open (IFILE, $ARGV[0]) or die "Cannot open Input File";

#Reading the entire file in an array

@array = <IFILE>;
$count = TotalLines();

print "The total number of Lines in $ARGV[0] is $count\n";
FindReplace();

#Definition of Subroutine to return Total number of Lines.
sub TotalLines ()
{
	#Simply return the array length.
	return @array;
}

#Definition of Subroutine to  search & replace.
sub FindReplace ()
{
	my $index=0;
	while(  $index <  $count) 
	{
		$array[$index] =~ s/$search/$replace/gi ;
		#show it in screen		
		print  $array[$index];
		$index++;
	}
}



