banana = input().split()
txt = list(map(float, banana))
txt.sort()
nota =  txt[1] + txt[2] + txt[3]
print ("%.1f"%nota)
