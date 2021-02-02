cont = 1
w1 = 1
w2 = w1
r = w2
mg = 0
while w1 != 0 and w2 != 0 and r != 0:
	banana = input()
	txt = banana.split()
	w1 = int (txt[0])
	w2 = int (txt[1])
	r = int (txt[2])
	m = (w1 * (1 + (r/30)) + w2 * (1 + (r/30)))/2
	mg = mg + m
	++cont
	if m != 0:
		if 1 <= m < 13:
			print ("Nao vai da nao")
		elif 13 <= m < 14:
			print ("E 13")
		elif 14 <= m < 40:
			print ("Bora, hora do show! BIIR!")
		elif 40 <= m <= 60:
			print ("Ta saindo da jaula o monstro!")
		else:
			print ("AQUI E BODYBUILDER!!")
--cont
mgf = mg/cont
if mgf > 40:
	print ("\n""Aqui nois constroi fibra rapaz! Nao e agua com musculo!")
