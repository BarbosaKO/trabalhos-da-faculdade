#numeros amigos
#print(k,"e amigo de", amigo)
#print("Nao existem numeros amigos")
import sys  
sys.setrecursionlimit(10000)

def div_rec(e):
	k=1
	soma=0
	for k in range(1,e,1):
		if e%k == 0:
			soma+=k
	return soma

def numeroAmigo(a,b,c,d):
	global g

	global aux
	global auxB


	if a<=b:
		amigo = div_rec(a)
		aux+=1
		if (amigo>=c) and (amigo<=d):
			if a<=amigo:
				print(a,"e amigo de", amigo)
				g+=1
		if auxB == aux+1:
			exit()
		numeroAmigo(a+1,b,c,d)

		
g = 0

aux = 0
auxB = 0

x,y = input().split(" ")
x = int(x)
y = int(y)
if (x>=1 and x<=1000)and(y>=1 and y<=1000):
	if x<=y:
		auxB = y-x
		numeroAmigo(x,y,x,y)
	if g == 0:
		print("Nao existem numeros amigos")