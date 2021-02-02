n = int (input ())
v = []
for i in range (n):
 v.append (int (input ()))
v.sort()
for i in range (n):
 if v[i] % 2 == 0:
  print (v[i])
for i in range(n - 1, -1, -1):
 if v[i] % 2 != 0:
  print (v[i])
