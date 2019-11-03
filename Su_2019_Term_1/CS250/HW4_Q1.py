#Compute the nth fibonacci number
def fib(x):
	a = 0
	fib_list = [0,1]
	while a < x-1:
		b = fib_list[a] + fib_list[a+1]
		fib_list.append(b)
		a += 1
	return fib_list[len(fib_list)-1] 

#index = int(input("Enter a number, n , for which the nth Fibonacci number will be returned: "))
#print(fib(index))

