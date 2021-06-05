def qtd_Rec(x,y,cont):
	aux2 = int(x/10)
	aux1 = x%10

	if aux2 != 0:
		if aux1 == y:
			cont+=1
			qtd_Rec(aux2,y,cont)
		else:
			qtd_Rec(aux2,y,cont)
	else:
		if x == y:
			cont+=1
		print(cont)
		exit()

a,b = input().split()
cont = 0
a = int(a)
b = int(b)

qtd_Rec(a,b,cont)