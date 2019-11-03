#This entire program considers 0 and negative even numbers (EG. -2, -4, etc.) in the set of even numbers
#Natural numbers are defined as the set of all positive integers not including 0

#Evens to natural numbers
def E_N(x):
	if x == 0: #Base
		return 1
	elif x % 2 == 0 and x > 0: #Positive case
		return x + 1
	elif x % 2 == 0 and x < 0: #Negative case
		return -x
	else: return x,'is not in the domain of even numbers'

#Natural numbers to integers
def N_Z(x):
	if x == 1:
		return int(0)
	elif x % 2 == 0 and x > 1:
		return int(x/2)
	elif x % 2 != 0 and x > 1:
		return int(-(x-1)/2)
	else: return x,'is not in the domain of natural numbers'

#Natural numbers to positive rationals
def N_pQ(x):
	from fractions import Fraction
	if float(x) % 1 == 0 and x > 0: #Only take natural numbers
		rationals = []
		for each in range(1,x+1): #create a list of rational numbers going by the diagonals of ([1/1,1/2,1/3...],[2/1,2/2,2/3...]...)
			a = 1
			b = each
			while a != each+1:
				c = a/b
				rationals.append(c)
				a += 1
				b -= 1	 	
	else: return x,'is not in the domain of natural numbers'
	reduced = []
	for eachvalue in rationals:
		if eachvalue not in reduced:
			reduced.append(eachvalue) #Remove any duplicates (reduce)
	return Fraction(reduced[x-1]).limit_denominator() #return the value at index[x-1] since lists index begins at 0. Limit denominator so x.3333 returns as a/3. I'm sure this is probably the least efficient method possible. This function will create 'x' number of diagonals corresponding to the list of all positive rationals, so the amount of time it takes to run scales exponentially with the value of the input. 

#Integers to all rationals
def Z_Q(x):
	if x == 0: return '0/1'
	elif float(x) % 1 == 0 and x > 0:
		return N_pQ(x) #if x is positive, let x map to positive rationals via the N_pQ function
	elif float(x) % 1 == 0 and x < 0: #if x is negative
		x = -x #make x positive
		return -1*N_pQ(x)	#throw it into the function to return a value. Then make the value negative so we cover the entire domain of rationals
	else: return x,"is not in the domain of integers"

#Even numbers to all rationals
def E_Q(x):
	if x % 2 == 0:
		a = x/2 #map even numbers to Z, then go from Z to Q using function Z_Q above
		return Z_Q(int(a))
	else: return x,'is not in the domain of even numbers'

if __name__ == '__main__':
	test = [-5,-4,-3,-2,-1,0,0.5,1,2,3,4,5]
	for each in test:
		print(Z_Q(each))
