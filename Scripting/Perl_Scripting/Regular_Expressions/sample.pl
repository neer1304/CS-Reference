my $NATURE = "the ratio between the book and the creation is mutual";

$NATURE =~ s/tion/SHEN/g;
print "$NATURE\n";

$NATURE =~ s/tio/SHYOW/g;
print "$NATURE\n";

$NATURE =~ s/he/HI/g;
print "$NATURE\n";

$NATURE =~ s/oo/U/g;
print "$NATURE\n";

$NATURE =~ tr/[A-Z]/[a-z]/;
print "$NATURE\n";


$NATURE =~ s/HI/he/gi;
print "$NATURE\n";
