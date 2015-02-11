a=["Hello","World",100,1234]     # declaration of list data type
print a
a[0:2]=[1,12,123]              # will insert given values at specified range
print a
a[0:2]=[]                      # Assignment of null list
print a
a[1:1]=['abc','xyz']           # insertion at a single index
print a
b=a                            # Copy the whole list
print b
print len(a)
a[:0]=a                        # copy itself at 0 index
print a
