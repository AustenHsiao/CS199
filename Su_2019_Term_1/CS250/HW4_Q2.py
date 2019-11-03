#Fibonacci numbers with recursion

def r_fib(x):
	if x == 0:
		return 0
	elif x == 1:
		return 1
	else:
		return r_fib(x-1) + r_fib(x-2)
	
a = int(input("Enter n : "))
print(r_fib(a))	
