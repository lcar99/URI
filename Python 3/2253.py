import string
while True:
 try:
  s = input()
  ls = len (s)
  flagM = 0
  flagm = 0
  flagn = 0
  flagb = 0
  flagp = 0
  for i in range (0,ls,1):
   if s[i] in string.ascii_lowercase:
    flagm = 1
   elif s[i] in string.ascii_uppercase:
    flagM = 1
   elif s[i] in string.digits:
    flagn = 1
   elif s[i] in string.whitespace:
    flagb = 1
    break
   elif s[i] in string.punctuation:
    flagp = 1
    break 
  if flagM == 1 and flagm == 1 and flagn == 1 and flagb == 0 and flagp == 0 and (6 <= ls <= 32):
   print ("Senha valida.")  
  else:
   print ("Senha invalida.")  
 except EOFError:
  break
