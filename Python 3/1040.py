batata = input()
txt = batata.split()
n1 = float (txt[0])
n2 = float (txt[1])
n3 = float (txt[2])
n4 = float (txt[3])
m = ((2 * n1) + (3 * n2) + (4 * n3) + n4)/10
print ("Media:", "%.1f"%m)
if m >= 7:
 print ("Aluno aprovado.")
elif 5 <= m < 7:
 print ("Aluno em exame.")
 nf = float (input ())
 print ("Nota do exame:", "%.1f"%nf)
 if (m + nf)/ 2 >= 5:
  print ("Aluno aprovado.")
 else:
  print ("Aluno reprovado.")
 print ("Media final:", "%.1f"%((m + nf)/ 2))
else:
 print ("Aluno reprovado.")
