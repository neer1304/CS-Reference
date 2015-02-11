#script to show scopes local/my
$global = 10;
my $i=10;

{
	my $i=99;#produces a new variable
	print "In side Block i = $i\n";
}

	print " Outside  Block i = $i\n";
	print " Outside  Block Global  = $global\n";
{
	local $global = 15;
	func();
}
	func(); #Call the function now it sees global =10;
sub func()
{
	print "The value of global =$global\n";
}




