#Question 7i of homework 6
#Show that (n+5 choose 5) == summation from i=1 to n, (6 choose i)*(n-1 choose i-1)

def recursive_choose(n):
	if k == 0:
		return 1
	elif  n == 0:
		return 0
	elif n > 0 and k > 0:
		return recursive_choose(n-1,k) + recursive_choose(n-1,k-1)

def fac(x):
	if x == 0:
		return 1
	elif x > 0:
		return x * fac(x-1)
def summation(n):
	count = 1
	summation_list = []
	while count <= 6:
		phrase1 = fac(6)/(fac(count)*fac(6-count))
		phrase2 = fac(n-1)/(fac(count-1)*fac(n-count))
		phrase = phrase1*phrase2
		summation_list.append(phrase)
		count += 1
	return sum(summation_list)
		
if __name__ == "__main__":
	print(recursive_choose(11,5))
