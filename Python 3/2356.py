while True:
 try:
  bac1 = input()
  bac2 = input()
  if bac2 in bac1:
   print ("Resistente")
  else:   
   print ("Nao resistente")
 except EOFError:
  break
