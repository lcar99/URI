d = int (input ())
a = d//365
d = d - (a * 365)
m = d//30
d = d - (m * 30)  
print (a, "ano(s)")
print (m, "mes(es)")
print (d, "dia(s)")
