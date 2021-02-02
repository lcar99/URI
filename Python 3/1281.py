dic = {}
n = int (input())
for i in range (n):
	k = int (input())
	for j in range (k):
		banana = input().split()
		key = banana[0]
		preco = float (banana[1])
		dic[key] = preco
	k = int (input())
	acu = 0
	for j in range (k):
		banana = input().split()
		key = banana[0]
		q = int (banana[1])
		acu += dic[key] * q
	print ("R$ ""%.2f"%acu)
