def concat_strings(a, b):
    str_type = type('')                             # save a type value!
    if type(a) == str_type and type(b) == str_type:
        return a + ' ' + b

print 'strings:', concat_strings('first', 'second')
print 'integers:', concat_strings(1, 2)

