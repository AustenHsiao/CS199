#expected value for flipping coin until heads

if __name__ == '__main__':
	summary = []
	for each in range(10000):
		summary.append(each*((1/2)**each))
	print(sum(summary)) 
	
