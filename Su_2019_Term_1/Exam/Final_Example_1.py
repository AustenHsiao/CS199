

user_in = input("Enter a string (n to terminate): ")
user_list = []

while user_in != 'n':
	user_list.append(user_in)
	user_in = input("Enter a string (n to terminate): ")

for each in user_list:
	if each[0].lower() == 'a' or each[0].lower() == 'e' or each[0].lower() == 'i' or each[0].lower() == 'o' or each[0].lower() == 'u':
		print(each,' ', end='')

n = 0
length = len(user_list)
user_list_r = []
while n < length:
	user_list_r.append(user_list[length - 1 - n])
	n += 1

for each in user_list_r:
	if each[0].lower() != 'a' and each[0].lower() != 'e' and each[0].lower() != 'i' and each[0].lower() != 'o' and each[0].lower() != 'u':
		print(each,' ',end='')
print('\n')
	


