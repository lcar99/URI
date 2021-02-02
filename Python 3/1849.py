import math
d = []
v = []
a, b, c, e = map(int, input().split())
d.append(a)
d.append(b)
v.append(c)
v.append(e)
d.sort()
v.sort()
queijo = d[0] + v[0]
if d[1] < v[1]:
	banana = d[1]
else:
	banana = v[1]
a = min(queijo, banana)
print ("%.0f"%(a**2))
