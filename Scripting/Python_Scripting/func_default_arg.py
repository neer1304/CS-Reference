def default_args(a, b='bar', c=13):
    return "a=%s, b=%s, c=%s" % (a, b, c)

print default_args('apa')                   # uses all default values
print default_args('s', b='py')             # overrides one default value
print default_args(c=-26, a='apa')          # override argument order

