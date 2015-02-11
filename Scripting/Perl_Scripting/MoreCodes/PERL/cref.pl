#script to show that default calling mechanism is call by ref.


my @array = (1, 199, 77, 99, 0, 22, 44);
#print the array elements before calling function transform

printf "The original array is @array\n";

transform(@array);

print "The modified  array is @array\n";


sub transform()
{
	
	#Flat list of arguments is @_
	
	
	foreach $var (@_)
	{
		$var = 2 * $var;
	}
	
}

