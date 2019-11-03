#Final problem #1 CS199
#Austen Hsiao
#take in a list of positive numbers from the user, terminated with a -1
#print out alternating even numbers

all_numbers = []
even = []
odd = []
user_in = int(input("Enter a positive number (-1 to terminate): ")) # get some numbers
while user_in != -1: #as long as its not -1, keep going
	if user_in > 0: #if the number is positive
		all_numbers.append(user_in) #put it into the all_numbers list
	else: print("This is not a valid input") #otherwise, its not valid
	user_in = int(input("Enter a positive number (-1 to terminate): ")) #ask again

for each in all_numbers: #for each thing in the all_numbers list
	if each % 2 == 0: even.append(each) #if its even, add it to even list 
	else: odd.append(each) #else, add it to the odd list

if len(even) < len(odd): #store the length of the smallest list as 'length'
	length = len(even)
else: length = len(odd)

if len(even) == 0: #if the length of even is nothing (0) (regardless of the size of the odd list), we cant print anything out because we need to return an even value first
	print("No Output") #so we'll print no 'output'
elif len(even) > 0 and len(odd) > 0: #otherwise, if the length is greater than 0
	for i in range(length): #incrementing from 0 to the length of the smallest list
		print(even[i],odd[i],'',end='') #print out the first even number followed by the first odd number. Then print the second even number and the second odd number
elif len(odd) == 0:
	print(even[0])
		
print()	#print out an empty line so it looks pretty	
