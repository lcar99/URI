duh = input ()
print ("NOTAS:")
b = duh.split('.')
d = int (b[0])
f  = int (b[1])
print (d//100 , "nota(s) de R$ 100.00")
d = d % 100
print (d//50 , "nota(s) de R$ 50.00")
d = d % 50
print (d//20 , "nota(s) de R$ 20.00")
d = d % 20
print (d//10 , "nota(s) de R$ 10.00")
d = d % 10
print (d//5 , "nota(s) de R$ 5.00")
d = d % 5
print (d//2 , "nota(s) de R$ 2.00")
d = d % 2
print ("MOEDAS:")
print (d , "moeda(s) de R$ 1.00")
print (f//50 , "moeda(s) de R$ 0.50")
f = f % 50
print (f//25, "moeda(s) de R$ 0.25")
f = f % 25
print (f//10, "moeda(s) de R$ 0.10")
f = f % 10
print (f//5, "moeda(s) de R$ 0.05")
f = f % 5
print (f, "moeda(s) de R$ 0.01")
