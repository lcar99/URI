while True:
 try:
  alpha = input()
  list (alpha)
  n = int (input ())
  word = input().split()
  l = list(map(int, word))
  for i in range (n):
   if i < n - 1:
    print (alpha[l[i] - 1], end = '')
   else:
    print (alpha[l[i] - 1])
 except EOFError:
  break
