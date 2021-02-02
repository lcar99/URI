banana = input ()
txt = banana.split ()
x = float (txt[0])
y = float (txt[1])
if x > 0:
 if y == 0:
  print ("Eixo X")
 elif y > 0:
  print ("Q1")
 else:
  print ("Q4")
elif x < 0:
 if y == 0:
  print ("Eixo X")
 elif y > 0:
  print ("Q2")
 else:
  print ("Q3")
else:
 if y == 0:
  print ("Origem")
 else:
  print ("Eixo Y")
