def xa(a):
 return len(a)
n = int (input ())
for i in range (n):
 s = input().split()
 s.sort(key=xa, reverse = True)
 print (' '.join(s))
