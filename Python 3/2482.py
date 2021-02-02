dic = {}
n = int (input())
for i in range (n):
	lingua = input ()
	frase = input ()
	dic[lingua] = frase
n = int (input())
for i in range (n):
	nome = input ()
	lingua = input ()
	print(nome)
	print(dic[lingua])
	print ("\n", end = "")
