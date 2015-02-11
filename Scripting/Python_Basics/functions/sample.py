#!/usr/bin/python

import random
def odd( spin ):
	"""odd(number) -&gt; boolean."""
	return spin%2 == 1

def report( spin ):
	"""Reports the current spin on standard output. Spin is a String"""
	if int(spin) == 0:
		print "zero"
		return
	if odd(int(spin)):
		print spin, "odd"
		return
	print spin, "even"

def spinWheel():
	"""Returns a string result from a roulette wheel spin."""
	t = random.randrange(8)
	if t == 7:
		return "00"
	return str(t)

for i in range(12):
	n= spinWheel()
	report( n )
