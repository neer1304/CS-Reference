#!/usr/local/bin/perl 

$answer = "no";

while ($answer ne "yes")
{
   print "Do you like Perl? ";
   $answer = <STDIN>;
   chomp $answer;
   if ($answer eq "yes") 
   {
      print "That is great!\n"; 
   } 
   else 
   {
     print "That is not the right answer! Try again.\n"; 
   }
}

=begin

Modify the program from above so that it asks users to "guess the lucky number". If the correct number is guessed the program stops, otherwise it continues 
forever. 

Modify the program so that it asks users whether they want to guess again each 
time. Use two variables, $number for the number and $answer for the answer to 
the question whether they want to continue guessing. The program stops if the 
user guesses the correct number or answers "no". (In other words, the program 
continues as long as a user has not answered "no" and has not guessed the 
correct number.)

=cut


