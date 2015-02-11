a = 'Hello world!'
b = "Hello world!"
print a == b
a = "Per's lecture"
print a
a = "One line.\nAnother line."
print a
b = """One line,
another Line."""
print b
a = "58"
print type(a)
b=int(a)
print b
print type(b)
f = float('1.2e-3')
print f                 # uses 'repr'
print f        	        # uses 'str'
print eval('23-12')

# print c = int('blah') 
			# what happens when something illegal is done?
		       	# Traceback (most recent call last):
 			# File "<stdin>", line 1, in ?
			# ValueError: invalid literal for int(): blahi
