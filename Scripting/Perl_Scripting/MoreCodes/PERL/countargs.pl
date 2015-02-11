#script to add the command Line args in Perl

my $count;
my $sum = 0;
my $sum1=0;
my $element = 0;

# @ARGV is the number of elements in the argument array ARGV
$count = @ARGV; #Note : The last array index is $#ARGV

#$0 is the file name
print "I am invoked as $0\n";
print "The number of command line args = $count\n";

if ($count > 0)  #Try the Loop if at least one argument is given
{
	#loop throuh the array, use the for loop
	for ($index = 0;$index < $count;$index++)
	{
		$sum = $sum + $ARGV[$index];
	}
	
	#Sum using foreach loop.
	foreach $element (@ARGV)  #foreach var (list) {}
	{
		$sum1 = $sum1 + $element ;
	}
}

print "The Sum using for loop is $sum\n";
print "The Sum using for each  loop is $sum1\n";
