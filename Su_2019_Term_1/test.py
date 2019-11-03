def recursive(a):
	if a == 1:
		return 1
	else:
		return a*recursive(a-1)+1

if __name__ == '__main__':
	user_num = int(input("Enter a number for this recursive call: \n"))
	print(recursive(user_num))
