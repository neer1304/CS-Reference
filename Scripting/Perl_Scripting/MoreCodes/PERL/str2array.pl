#script to  show how to convert a string to an array.

my $istring;
my $slength;
my $ostring;
my $tempstring = "";


#Accept i/p from keyboard...

print "Enter a string\n" ;

$istring = <STDIN>;

#remove the return from the string
chop($istring);

my $slength = length($istring);

#Print the string Length.

print "The length of the string $istring is $slength\n";

#Convert the String 2 an array, used the split function.

my @strarray = split(//, $istring);

my $alength = @strarray;

print "The length of the string array is $alength\n";

print "Individual Array elements are \n";

foreach $var (@strarray)
{
	print "$var\n";
}








