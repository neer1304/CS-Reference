#!/usr/bin/python
hollow='There is the Shadow'
song="Me and my Shadow"
index=hollow.find('the')
print "The starting index of 'the' in '%s' is %d"\
% (hollow,index)
index=song.find('a')
print "The index of the first '%s' in '%s' is %d"\
% ('a',song,index)
hollow=hollow.replace('Shadow','Light')
print "A hopeful message: " + hollow
name=raw_input("Enteryour name: ")
name=name.capitalize()
print "Hello %s, welcome to the party, pal" % (name)
upsong=song.upper()
print "Uppercase: " + upsong
