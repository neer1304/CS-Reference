w = open('output.txt', 'w')     # write mode (text by default)
w.write('stuff')                # does *not* add newline automatically
w.write('\n')
w.write('more\n and even more\n')
w.close()
