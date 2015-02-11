a=[2,3]
b=[1,a,4]
print len(a)		# 2
print len(b)		# 3
print b[0]		# 1
print b[1]		# [2,3]
print b[2]		# 4
print b[1][0]		# 2
print b[1][1]		# 3
b[1].apend('Extra')   
print b		        # [1, [2, 3, 'Extra'], 4]
print a			# [2, 3, 'Extra']

