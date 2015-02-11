#Syntax

# if condition
#	then
#		command1 if condition is true or if exit status
#		of condition is 0 (zero)
#		...
#		...
# fi

clear
#!/bin/sh
#
#Script to print file
#

if cat $1
then
 echo -n "\n\nFile $1, found and successfully echoed"
fi

