#script to check whether a given string is a palindrome

my $istring;
my $slength;
my $ostring;
my $tempstring = "";


#Accept i/p from keyboard...

print "Enter a string\n" ;

$istring = <STDIN>;

#remove the return from the string
chop($istring);

#Save input string...
$ostring = $istring;


#find the string length
$slength = length($istring);

print "The Length of the String is $slength\n";

#Reverse the string & store it in tempstring, chop 
#destroys the original string also

for($index = 0 ; $index < $slength; $index++)
{
	#chop returns the last character chopped.
	$tempstring = $tempstring . chop($istring); #.is the string concat op.
}

if ($tempstring eq $ostring)
{
	print "$ostring is a palindrome";
}
else
{
	print "$ostring is a not a  palindrome";
}






