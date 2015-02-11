def unspec_args(a, *args):                 # name 'args' is a convention
    return "a=%s, others=%s" % (a, args)

print unspec_args('bla', 'qwe', 23, False)

