#Syntax:

#           for { variable name } in { list }
#           do
#                    execute one for each item in the list until the list is
#                    not finished (And repeat all statement between do and done)
#           done

clear
read a
for i in $a
do
echo "Welcome $i times"
done
