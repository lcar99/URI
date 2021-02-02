while True:
 try:
  time = input().split()
  h = int(time[0])
  m = int(time[1])
  h = h * 60
  qt = h//m
  val = input().split()
  val1 = list(map(float, val))
  med = (sum (val1))/qt
  ac = 0
  for i in range(qt):
   ac += (val1[i] - med)**2
  p = (ac / (qt - 1))**(1/2)
  print ("%.5f"%p)
 except EOFError:
  break
