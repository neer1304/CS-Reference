#!/usr/bin/perl -w
# numberspeller:  prints out word approximations of numbers
# simple version, only does single-digits

$exit = "";  # whether or not to exit the script.

while ($exit ne "n") {

    while () {
        print 'Enter the number you want to spell(0-9): ';
        chomp($_ = <STDIN>);
        if (/^\d$/) {
            print "Thanks!\n";
            last;
        } elsif (/^$/) {
            print "You didn't enter anything.\n";
        } elsif (/\D/) {        # nonnummbers
            if (/[a-zA-z]/) { # letters
               print "You can't fool me.  There are letters in there.\n";
            } elsif (/^-\d/) { # negative numbers
               print "That's a negative number.  Positive only, please!\n";
            } elsif (/\./) { # decimals
               print "That looks like it could be a floating-point number.\n";
              print "I can't spell a floating-point number.  Try again.\n";
            } elsif (/[\W_]/) {  # other chars
                print "huh?  That *really* doesn't look like a number\n";
            }
        } elsif ($_ > 9) {
            print "Too big!  0 through 9, please.\n";
        }
    }

    print "Number $_ is ";
    /1/ && print 'one';
    /2/ && print 'two';
    /3/ && print 'three';
    /4/ && print 'four';
    /5/ && print 'five';
    /6/ && print 'six';
    /7/ && print 'seven';
    /8/ && print 'eight';
    /9/ && print 'nine';
    /0/ && print 'zero';
    print "\n";

    while () {
        print 'Try another number (y/n)?: ';
        chomp ($exit = <STDIN>);
        $exit = lc $exit;
        if ($exit =~ /^[yn]/) {
            last;
        }
        else {
            print "y or n, please\n";
        }
    }
}
