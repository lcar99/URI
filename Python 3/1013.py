en = input()
ent = en.split()
a = int (ent[0])
b = int (ent[1])
c = int (ent[2])
mab = (a + b + abs (a - b))/2
ovo = (mab + c + abs (mab - c))/2
print ("%.0f"%ovo, "eh o maior")
