#script that finds all lines from a file containing the string Linux( any case )
#LINUX
#JCVHASJCVSHCV              LiNUX


#Fetch Number of file From Cmd Line
$NumberOfFile = @ARGV;

#Report Error and exit for Improper Args
if ( $NumberOfFile == 0)
{
	print "Enter at least one Filename USAGE:nsloc <file1> <file2> ..\n";
	die;
}

print "You have requested for $NumberOfFile File(s)to process\n\n";

my @array =();
my $count;

#Iterate throgh the Cmd Line ASrgs.
foreach (@ARGV)
{
	$CurrentFilename = $_;
	#Clear the array...
	@array = ();
	if (open(fh, $CurrentFilename) 
	{ 
		@array = <fh> ; #Read all the lines in $array[0], $array[1]
		$count = @array; #Size of the array gives the number of lines..
		CLinux($CurrentFilename);
	}
	else
	{
		print "Cannot open $CurrentFilename";
	}
		
	
	
}



#Definition of Subroutine to print those lines containing linux
sub CLinux ()
{
	my $index=0;
	print "Prosessing File : $_[0]\n";	
	while(  $index <  $count) 
	{
		if ($array[$index] =~ /[lL][iI][Nn][uU][xX]/)
		{
			print " Line No -$array[$index]";
		}
	

	$index++;
	}
	
}





=Comment
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
=Comment end



