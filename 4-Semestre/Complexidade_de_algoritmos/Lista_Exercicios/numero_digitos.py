def num_digi(x,y):
	a = int(x/10)
	if a!=0:
		y += 1
		num_digi(a,y)
	else:
		print(y+1)

digi = int(input())
cont=0
num_digi(digi,cont)