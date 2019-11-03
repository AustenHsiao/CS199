def move_disk(n):
	#n is a binary number string that defines our current position. This function will tell us which disk to move
	#the discs are numbered such that the largest number is the base and 0 is the top at the starting position
	next_move = bin(int(n,2) + 1) #add one to the binary number for our next move
	next_move = next_move[2:].zfill(len(n)) #To account for leading 0s in the input and the '0b' before binary numbers, slice from [2:] and add zeroes to equal the number of digits in len(n)
	n = n.zfill(len(next_move)) #If there are no leading zeroes on 'n', then we need to add enough leading zeroes to 'n' in order to make the length of n and next_move the same
	for i in range(len(n)): 
		if next_move[i] != n[i]: #compare the digits in next_move and n. Return the position of the change from the right-- so if the 3rd digit from the right is a 1, return 3. 
			return (len(n) - i - 1)	

print(move_disk('110'))
