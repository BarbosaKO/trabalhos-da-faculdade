def resto(x,y):
	if x>=y:
		return resto(x-y,y)
	elif x<y:
		return x

a = int(input())
b = int(input())

if a<0:
	a = -(a)
if b<0:
	b = -(b)
if b != 0:
	print(resto(a,b))
else:
	print(-1)