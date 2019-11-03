#This is the second question of the practice midterm questions. 
#Take in a sequence of non-zero numbers from the user, terminating with a 0. Output the sum of the numbers that are larger than the first number and the sum of the numbers that are smaller than the first number

Large_Answer = 0
Smaller_Answer = 0
User_Num = 1
Compare_Num = int(input("Enter non-zero integers (Enter 0 to terminate): "))
while User_Num != 0:
	User_Num = int(input("Enter a non-zero integer (Enter 0 to terminate): "))
	if User_Num > Compare_Num:
		Large_Answer += User_Num
	elif User_Num < Compare_Num:
		Smaller_Answer += User_Num
print("Sum of larger numbers:",Large_Answer,"\nSum of smaller numbers:",Smaller_Answer)
