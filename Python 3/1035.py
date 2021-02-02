batata = input()
txt = batata.split()
a = int (txt[0])
b = int (txt[1])
c = int (txt[2])
d = int (txt[3])
if b > c and d > a and c + d > a + b and c > 0 and d > 0 and a % 2 == 0:
 print ("Valores aceitos")
else:
 print ("Valores nao aceitos")
