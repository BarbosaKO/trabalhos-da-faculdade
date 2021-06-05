def mdc(a, b):
   if b == 0:
       return a
   resto = a % b
   a = b
   b = resto
   print(a,b,'\n')
   return mdc(a, b)

a = int(input())
b = int(input())
result = mdc(a,b)
print(result)