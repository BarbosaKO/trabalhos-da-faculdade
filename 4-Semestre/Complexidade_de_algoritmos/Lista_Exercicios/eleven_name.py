def fibo(x):
	global lista
	if x>2:
		lista.append(fibo(x-2)+fibo(x-1))
	else:
		return 1
def eleven(a,Lista):
	for k in range(1,a,1):
		Lista.append(fibo(k))

n = input()
n = int(n)

lista = []
#eleven(n,lista)
fibo(n)
print(lista[4])
