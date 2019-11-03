#practice midterm example 1
# A sum of fractions, write a program that allows the user to input an integer, n. If n is positive, odd number, perform the calculation (See d2l page) and output the value. 
#Otherwise, print the message, "Invalid Input", and end the program

User_Integer = int(input("Enter an integer: "))
numerator = User_Integer
denominator = 1
answer = 0
if User_Integer % 2 != 0 and User_Integer > 0:
	while numerator > 0:
		answer += numerator/denominator
		numerator -= 2
		denominator += 2
	print("Output:",answer)
elif User_Integer % 2 == 0 or User_Integer < 0:
	print("Invalid Input")		
