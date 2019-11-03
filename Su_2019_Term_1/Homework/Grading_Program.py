#Assignment 2
#Austen Hsiao
#All assignments, mt, and final are assumed to be out of 100 pts
#3 assignments, 1 MT, 1 Final

n = 1 
A = 0
B = 0
C = 0
D = 0
F = 0
Overall_Sum = 0

Assignment_Weight = float(input("Enter the percentage that assignments count towards the final grade: ")) ##Prompt user to enter the weights of assignments, the MT, and final exam
Midterm_Weight = float(input("Enter the percentage that the midterm counts towards the final grade: "))
Final_Weight = float(input("Enter the percentage that the final counts towards the final grade: "))

if Assignment_Weight + Midterm_Weight + Final_Weight != 100: ##Check to see if the percentages add up to 100. Notify user and terminate if it does not
	print("The percentages do not add up to 100%")
else: 
	Num_Students = float(input("Enter the number of students: ")) ##Continue to ask user for the number of students if the weights total 100
	while n <= Num_Students:
		print("Enter assignment #1 grade for student ", n,": ",end="",sep="") ##Enter grade (out of 100) for assignment1, 2, 3, MT, and final exam
		Assignment_1_Raw_Grade = float(input())
		print("Enter assignment #2 grade for student ", n,": ",end="",sep="")
		Assignment_2_Raw_Grade = float(input())
		print("Enter assignment #3 grade for student ", n,": ",end="",sep="")
		Assignment_3_Raw_Grade = float(input())
		print("Enter midterm grade for student ", n,": ",end="",sep="")
		Midterm_Grade = float(input())
		print("Enter final exam grade for student ", n,": ", end="", sep="")
		Final_Grade = float(input())
		Overall_Grade = (Assignment_Weight*((Assignment_1_Raw_Grade+Assignment_2_Raw_Grade+Assignment_3_Raw_Grade)/300)) + (Midterm_Weight * Midterm_Grade/100) + (Final_Weight*Final_Grade/100) ##Calculate overall grade, each submission is out of 100, so we divide by 100 to find the fractional quantity
		Overall_Sum += Overall_Grade ##Define overall sum as the summation of all overall grades in the course so we can find the class average in the end
		if Overall_Grade < 60: F += 1
		elif Overall_Grade >= 60 and Overall_Grade < 70: D += 1 ##Determine which grade bracket each student falls into and increment the correct bracket (A-F)
		elif Overall_Grade >= 70 and Overall_Grade < 80: C += 1
		elif Overall_Grade >= 80 and Overall_Grade < 90: B += 1
		elif Overall_Grade >= 90: A += 1 
		n += 1 ##Increment the number of students so this loop can end when n > number of students
	print("GRADE DISTRIBUTION:\tA\tB\tC\tD\tF\n\t\t\t",A,"\t",B,"\t",C,"\t",D,"\t",F,"\nCLASS AVERAGE =",Overall_Sum/Num_Students) ##Print the grade distribution and class average





