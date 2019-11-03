#Midterm question 1: The sum of sums
#Austen Hsiao 07/09/19

n = int(input("Enter a non-zero integer: "))
numerator = 2
denominator = 2
answer = 0 
initial = 2

if n < 0 or n % 2 != 0:
	print("Invalid Number")
elif n % 2 == 0 and n > 0:
	while initial <= n: 
		answer += numerator/denominator
		numerator = (numerator+initial+2)
		denominator += 2
		initial += 2
	print("Output:", answer)
		
