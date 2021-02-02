noel = "a"
while True:
 try:
  noel = input()
  if noel != '':
   if noel == 'brasil' or noel == 'portugal':
    print ("Feliz Natal!")
   elif noel == 'alemanha':
    print ("Frohliche Weihnachten!")
   elif noel == 'austria':
    print ("Frohe Weihnacht!")
   elif noel == 'coreia':
    print ("Chuk Sung Tan!")
   elif noel == 'espanha' or noel == 'argentina' or noel == 'chile' or noel == 'mexico':
    print ("Feliz Navidad!")
   elif noel == 'grecia':
    print ("Kala Christougena!")
   elif noel == 'estados-unidos' or noel == 'inglaterra' or noel == 'canada' or noel == 'australia' or noel == 'antardida':
    print ("Merry Christmas!")
   elif noel == 'suecia':
    print ("God Jul!")
   elif noel == 'turquia':
    print ("Mutlu Noeller")
   elif noel == 'irlanda':
    print ("Nollaig Shona Dhuit!")
   elif noel == 'belgica':
    print ("Zalig Kerstfeest!")
   elif noel == 'italia' or noel == 'libia':
    print ("Buon Natale!")
   elif noel == 'siria' or noel == 'marrocos':
    print ("Milad Mubarak!")
   elif noel == 'japao':
    print ("Merii Kurisumasu!")
   else:
    print ("--- NOT FOUND ---")
 except EOFError:
   break
