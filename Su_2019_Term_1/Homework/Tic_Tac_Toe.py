#Tic tac toe
#Austen Hsiao
#Assignment 4

def player_move(move_list):
	x = int(input("Enter a position to take: ")) #What spot does the player want to take?
	if x in move_list: #if it's a viable move
		return x #return the value
	else:
		print("\nThis is an invalid move. Enter an open position.") #if its not a viable move (it doesnt exist in the moves list)
		return player_move(move_list) #rerun the function

def print_board(board_list): #Print out board list by 3s
	n = 0
	print('\n')
	while n < 3:
		print('|',board_list[n],'|',end=' ')
		n += 1
	print('\n')
	while n >= 3 and n < 6:
		print('|',board_list[n],'|',end=' ')
		n += 1
	print('\n')
	while n >= 6 and n < 9:
		print('|',board_list[n],'|',end=' ')
		n += 1
	print('\n')	
	
def win_condition(board_list): #Check if somebody won. If somebody triggers a win condition, return True
	if board_list[0] == board_list[1] and board_list[0] == board_list[2]: return True
	elif board_list[3] == board_list[4] and board_list[3] == board_list[5]: return True
	elif board_list[6] == board_list[7] and board_list[6] == board_list[8]: return True
	elif board_list[0] == board_list[3] and board_list[0] == board_list[6]: return True
	elif board_list[1] == board_list[4] and board_list[1] == board_list[7]: return True
	elif board_list[2] == board_list[5] and board_list[2] == board_list[8]: return True
	elif board_list[2] == board_list[4] and board_list[2] == board_list[6]: return True
	elif board_list[0] == board_list[4] and board_list[0] == board_list[8]: return True
	else: return False

if __name__ == '__main__':
	board = [' 1',' 2',' 3',' 4',' 5',' 6',' 7',' 8',' 9'] #this is the linearized board
	moves = [i for i in range(1,10)] #these are our available moves
	num_moves = 0 # there will be a total of 9 moves, so we can count 0-9

	print("\nINSTRUCTIONS: Player 1 moves first. To move, specify a position to take (1-9).")
	print_board(board) #show us the board

	while num_moves != 9: 
		#P1 MOVES
		print("~~~PLAYER 1~~~") 
		p1_move = player_move(moves) #store p1 move
		board[p1_move-1] = ' X' #change the value at board[x-1] to 'X' 
		moves.remove(p1_move) #remove the value player 1 used from the available moves
		print_board(board) #print out the board
		num_moves += 1	#used 1 move
		if win_condition(board): #check if p1 won
			print("PLAYER 1 WINS!")
			break	

		if num_moves < 9:
			#P2 MOVES
			print("~~~PLAYER 2~~~")
			p2_move = player_move(moves)
			board[p2_move-1] = ' O'
			moves.remove(p2_move)
			print_board(board)
			num_moves += 1
			if win_condition(board):
				print("PLAYER 2 WINS!")
				break

	if win_condition(board) == False: #if we make it this far, if nobody has won, it must be a tie
		print("NOBODY WINS.")
