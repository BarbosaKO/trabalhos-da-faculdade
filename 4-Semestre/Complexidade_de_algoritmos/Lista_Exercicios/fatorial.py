def fat(n):
	if n>0:
		return n*fat(n-1)
	elif n == 1:
		return 1
	elif n == 0:
		return 1
	else:
		exit()

while True:
	x = int(input())
	r_fat = fat(x)
	print(r_fat)