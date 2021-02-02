noel = "a"
while True:
 try:
  noel = input ()
  if noel != '':
   grau = float (noel)
   gm = 15/60
   gs = gm/60
   s = int (grau/gs)
   m = s//60
   s = s % 60
   h = m//60
   m = m % 60
   h += 6
   h = h % 24
   if 6 <= h < 12:
    print ("Bom Dia!!")
   elif 12 <= h < 18:
    print ("Boa Tarde!!")
   elif 18 <= h <= 23:
    print ("Boa Noite!!")
   else:
    print ("De Madrugada!!")
   print ("%02d:%02d:%02d" %(h,m,s)) 
 except EOFError:
  break
 
