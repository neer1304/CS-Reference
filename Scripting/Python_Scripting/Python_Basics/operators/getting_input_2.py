#!/usr/bin/python
year=raw_input("Please enter a year:")
year=int(year) #convert input string to int
ten=year+10
print "A decade later will be", ten
x=raw_input("Enter x coord: ") #prompt along with input
x=float(x) #convert input string to float
y=raw_input("Enter y coord: ")
y=float(y)
r=(x**2+y**2)**0.5
print "Distance from origin is", r
