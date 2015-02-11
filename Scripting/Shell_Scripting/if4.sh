#
#!/bin/sh
# $cript to test if..elif...else
#
clear
read -p "enter a value" a
if [ $a -gt 0 ]; then
  echo "$a is positive"
elif [ $a -lt 0 ]
then
  echo "$a is negative"
elif [ $a -eq 0 ]
then
  echo "$a is zero"
else
  echo "Opps! $a is not number, give number"
fi
