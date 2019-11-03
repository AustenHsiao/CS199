#Second final problem for CS199 practice
user_list = []
user_in = int(input("Enter positive integers (-1 to terminate): "))

while user_in != -1:
	user_list.append(user_in)
	user_in = int(input("Enter positive integers (-1 to terminate): "))

mean = sum(user_list)/len(user_list)

count = 0
for each in user_list:
	if each % 2 == 0 and each <= mean + 10 and mean - 10 <= each:
		count += 1
print(count)	
