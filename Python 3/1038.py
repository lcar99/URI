batata = input()
txt = batata.split()
c = int (txt[0])
q = int (txt[1])
if c == 1:
 print ("Total: R$","%.2f"%(q * 4.0))
elif c == 2:
 print ("Total: R$","%.2f"%(q * 4.5))
elif c == 3:
 print ("Total: R$","%.2f"%(q * 5.0))
elif c == 4:
 print ("Total: R$","%.2f"%(q * 2.0))
else:
 print ("Total: R$","%.2f"%(q * 1.5))
