import re
word = 'asdfaehjioytgiuhhjjiouhjaeijdjjaouhjskkeuiohjj'
print re.findall('[aeiou]{2,}', word)
print len(re.findall('[aeiou]{2,}', word))
