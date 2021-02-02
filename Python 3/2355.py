import math
t = 1
while t != 0:
 t = int (input ())
 td = 7/90
 tb = 1/90
 d = math.ceil (t * td)
 b = math.floor (t * tb)
 if t != 0:
  print ("Brasil", b, "x", "Alemanha", d)
