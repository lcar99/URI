d = int (input ())
print (d)
print (d//100 , "nota(s) de R$ 100,00")
d = d % 100
print (d//50 , "nota(s) de R$ 50,00")
d = d % 50
print (d//20 , "nota(s) de R$ 20,00")
d = d % 20
print (d//10 , "nota(s) de R$ 10,00")
d = d % 10
print (d//5 , "nota(s) de R$ 5,00")
d = d % 5
print (d//2 , "nota(s) de R$ 2,00")
d = d % 2
print (d , "nota(s) de R$ 1,00")
