mat = [
	[1, 2, 3],
	[4, 5, 6],
	[7, 8, 9],
	]
print [[row[i] for row in mat] for i in [0, 1, 2]]


for i in [0, 1, 2]:
    for row in mat:
        print row[i],
    print


print zip(*mat)

