import re

seq = "MAKEVFSKRTCACVFHKVHAQPNVGITR"

zinc_finger = re.compile('C.C..H..H')    # compile regular expression pattern
print zinc_finger.findall(seq)

two_charged = re.compile('[DERK][DERK]')
print two_charged.findall(seq)

