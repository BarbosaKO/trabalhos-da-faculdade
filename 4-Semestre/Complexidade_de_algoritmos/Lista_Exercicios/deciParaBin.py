def binario(num):
	n=0
	if (int(num/2) != 0):
		n = int(num/2)
		binario(n)
		print(num%2)
	else:
		print(num%2)

deci = int(input())
binario(deci)