import re
word = 'supercalifragulisticexpialidocious'
print re.findall('[aeiou]', word)
print len(re.findall('[aeiou]', word))
