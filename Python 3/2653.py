tesouro = ['.']
i = 0
while True:
 try:
  joia = input ()
  if joia not in tesouro:
   i += 1
   tesouro.append(joia)
 except EOFError:
  print (i)
  break  
   
