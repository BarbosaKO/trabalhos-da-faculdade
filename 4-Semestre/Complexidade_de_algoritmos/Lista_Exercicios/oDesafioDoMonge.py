def func_Secreta(a):
	if a == 0:
		return 10
	elif a == 1:
		return 11
	elif a == 2:
		return 27
	else:
		return func_Secreta(a-2)-func_Secreta(a-3)

while True:
    try:
    	print(func_Secreta(int(input())))
    except:
    	break