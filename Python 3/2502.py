import string
while True:
	try:
		txt = input().split()
		l = int(txt[1])
		cifra1 = input().upper()
		cifra2 = input().upper()
		cifra1m = cifra1.lower()
		cifra2m = cifra2.lower()
		for i in range (l):
			aaa = input ()
			ls = len (aaa)
			frase = list (aaa)
			for j in range(ls):
				if cifra1.find(aaa[j]) != -1:
					a = cifra1.find(aaa[j])
					if frase[j] not in string.ascii_letters:
						frase[j] = cifra2[a].lower()
					else:	
						frase[j] = cifra2[a] 
				elif cifra1m.find(aaa[j]) != -1:
					a = cifra1m.find(aaa[j])
					if frase[j] not in string.ascii_letters:
						frase[j] = cifra2m[a].lower()
					else:	
						frase[j] = cifra2m[a] 
				elif cifra2.find(aaa[j]) != -1:
					a = cifra2.find(aaa[j])
					if frase[j] not in string.ascii_letters:
						frase[j] = cifra1[a].lower()
					else:
						frase[j] = cifra1[a]
				elif cifra2m.find(aaa[j]) != -1:
					a = cifra2m.find(aaa[j])
					if frase[j] not in string.ascii_letters:
						frase[j] = cifra1m[a].lower()
					else:
						frase[j] = cifra1m[a]
			print ("".join(frase))
		print("\n", end = "")
	except EOFError:
		break
