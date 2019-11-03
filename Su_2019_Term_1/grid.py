#QUestion 6c of homework 6
#using recursion to find the number of paths on a given grid from the top left to the bottom right. We can only move along the grid to the right and down.

def paths(r,c):
	if r == 0 or c == 0:
		return 1
	else:
		return paths(r-1,c) + paths(r,c-1)

if __name__ == "__main__":
	r = int(input("Enter the number of rows: "))	
	c = int(input("Enter the number of columns: "))
	print(paths(r,c))
