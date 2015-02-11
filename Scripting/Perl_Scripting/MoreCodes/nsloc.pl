#Last updated on 26-03-2010
#Mentioning Functions Declarations below

sub CountBlankLines ();
sub CountCplusplusComments();
sub  CountCComments();
sub TotalLines ();

#Fetch Number of file From Cmd Line
$NumberOfFile = @ARGV;

#Report Error and exit for Improper Args
if ( $NumberOfFile == 0)
{
	print "Enter at least one Filename USAGE:nsloc <file1> <file2> ..\n";
	die;
}

print "You have requested for $NumberOfFile File(s)to process\n\n";

#Having two globals array(used to fetch the lines of a file), count(No of Lines)
my @array =();
my $count;

#Print the Header 
	print "File     #Lines    #Blanks   #CC/**/   #C++// 	 #SLOC\n";
	print "-------------------------------------------------------\n";

#Iterate throgh the Cmd Line ASrgs.
foreach (@ARGV)
{
	$CurrentFilename = $_;
	open(fh, $CurrentFilename) || die "Cannnot open file $CurrentFilename"; 
	@array = <fh> ; 
	$NumLines = TotalLines();
	$count=$NumLines;
	$BlankLines = CountBlankLines();
	$Comments =  CountCComments();
	$CPComments =CountCplusplusComments();
	$SLOC = $NumLines - ($BlankLines + $Comments + $CPComments);
	#Release Array
	@array = ();
	
	#Print details
	print "$_\n";
	print "         $NumLines         $BlankLines          $Comments         $CPComments        $SLOC";
	print "\n";
}

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



#Definition of Subroutine to return number of C++ Comments
#C++ Comments = (any seq of space)//(any seq of characters)NL
sub CountCplusplusComments()
{
	my $index = 0;
	my $CplusplusComm = 0;
	while(  $index <  $count) 
	{
		if ($array[$index] =~ /^[ \t]*\/\/[.]*/)
		{
			
			#print $array[$index] ;
			$CplusplusComm++;
	
		}
    		$index++;
	}
	return $CplusplusComm;
}


#Definition of Subroutine to return number of C Single Line and Block Comment.
sub  CountCComments()
{

	my $index=0; 
	my $singlelinecomment = 0;
	my $blockcomment = 0;
	
	while ($index <  $count) 
	{
		#(any sequence of space)/*(any seq of char)
		#*/(any sequence of char )(NewLine or No NL)
		#The above RE is modelled below, which is possibly 
		#not exactly as per K&R, but suffice time being.	

		if ($array[$index] =~ /^[ \t]*\/\*.*\*\/.*\n*/) 
		{
			#print "got a C Comment line at $index\n";
			#print $array[$index] ;
			$singlelinecomment++;
			$index++;
			#Continue the while
			next;

		}
	
		#Try the Block Comment start for that line
		#Block Comment:(any seq of space)/*(any seq of char)NL
		#(any seq of char)NL
		#(any seq of char)*/(any seq of char)NL  
		
		if ($array[$index] =~/^[ \t]*\/\*.*\n/)
		{	
			$blockcomment++;
			#print $array[$index];
		
			#Try to get the end of Block Comment also..
			$index++;
			while ($index < $count)
			{
				if ($array[$index] =~/^.*\*\/.*\n/)
				{
					#print $array[$index];
					$blockcomment++;
					#Exit from Innner While
					last;
				}
				#print $array[$index];
			
				$blockcomment++;
				$index++;
			}
		}
	
	#Check the next Line 

	$index++;

	} #Outer While Ends.

	#We need to return the sum of Single Line and Block Comments.
	return $singlelinecomment + $blockcomment;

}


