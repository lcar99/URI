n = int (input ())
for i in range(n):
 cont = 0
 a = int (input ())
 for j in range(1,a - 1,1):
  if a % j == 0:
   cont += j
 if a == cont:
  print (a, "eh perfeito")
 else:
  print (a, "nao eh perfeito")
