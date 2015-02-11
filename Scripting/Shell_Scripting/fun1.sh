# Syntax:

#           function-name ( )
#           {
#                command1
#                command2
#                .....
#                ...
#                commandN
#                return
#           }

# At the end of file add following in /etc/bashrc file
#
# today() to print formatted date
#
# To run this function type today at the $ prompt
# Added by Vivek to show function in Linux
#
#today()
#{
echo "This is a `date +"%A %d in %B of %Y (%r)"`"
#return
#}

