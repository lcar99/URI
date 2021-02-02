banana = input().split()
n = int(banana[0])
h = int(banana[1])
for i in range(n):
 titao = input().split()
 a = len(titao) - 1
 if int(titao[a]) > h:
  del titao[-1]
  print (' '.join(titao))
