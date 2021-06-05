def digPar(x,aux):
	global resp
	if aux>=0:
		if ((int(x[aux])%2) == 0)and(aux>=0):
			resp+=1
			digPar(num, aux-1)
		else:
			digPar(num, aux-1)
	else:
		print(resp)
		exit()

		
resp = 0
num = input()
digPar(num, len(num)-1)