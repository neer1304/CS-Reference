#Copies Non Blank Lines from File1( Argv[0] ) to file2 (Argv[1])


#Fetch Number of file From Cmd Line

$NumberOfFile = @ARGV;


#Report Error and exit for Improper Args
if ( $NumberOfFile < 2 )
{
	print "Enter  two  Filenames: \n";
	die;
}


#Having two globals array(used to fetch the lines of a file), count(No of Lines)
my @array = ();
my @narray = ();
my $count;

#Opening bothe i/p and o/p files
open (ifile, $ARGV[0]) || die "Cannot open Input File";
open (ofile, ">$ARGV[1]") || die "Cannot open Output File";

#Reading the entire file in an array

@array = <ifile>;
$count = TotalLines();
print "The total number of Lines in $ARGV[0] is $count\n";
my $blanks = CountBlankLines();
print "The total number of Blank Lines in $ARGV[0] is $blanks\n";

#Fetch Non Blank lines in Array narray
GetNonBlanks();
#Write the Non Blank lines in  the O/P File
WriteNonBlanks();



#Definition of Subroutine to return Total number of Lines.
sub TotalLines ()
{
	#Simply return the array length.
	return @array;
}

#Definition of Subroutine to return number of blank lines
sub CountBlankLines ()
{
	my $index=0;
	my $NoOfBlanks = 0;
	while(  $index <  $count) 
	{
		if ($array[$index] =~ /^[ \t]*\n/)
		{
			$NoOfBlanks++;
		}
	

	$index++;
	}
	return $NoOfBlanks;
}

sub GetNonBlanks()
{
	my $index=0;
	my $nindex = 0;
	while(  $index <  $count) 
	{
		if ($array[$index] =~ /^[ \t]*\n/)
		{
			$index++;
			#If blank then continue the loop
			next;	
		}
	

		#Store the Non Blank Lines in an array
		$narray[$nindex] = $array[$index];
		print "$narray[$nindex]\n";
		$index++;
		$nindex++;

	}
}
	
sub WriteNonBlanks()
{
	my $lines;
	foreach $lines (@narray)
	{
		print ofile $lines;
	}
	
}


