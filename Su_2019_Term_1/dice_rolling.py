#homework 6, Q7b
count = 1
counter = 0
list_all = []
for eoch in range(1,7):
	for each in range(1,7):
		for each1 in range(1,7):
#			for each2 in range(1,7):
#				for each3 in range(1,7):
#					for each4 in range(1,7):
			dice = eoch,each,each1#,each2,each3,each4 ## FOR 3 DICE
			list_all.append(dice)

check2 = []
for each in list_all:
	check1 = []
	for eachthing in each:
		if eachthing not in check1:
			check1.append(eachthing)
#	print(each, len(check1))
	if len(check1) == 3: ##<-- CHANGE HERE FOR THE NUMBER OF DISTINCT VALUES
		counter += 1
		check2.append(each)
no_repeats = []
for each in check2:
	zero = [0,0,0,0,0,0]
	for eachelement in each:
		if eachelement == 1:
			zero[0] += 1
		elif eachelement == 2:
			zero[1] += 1
		elif eachelement == 3:
			zero[2] += 1
		elif eachelement == 4:
			zero[3] += 1
		elif eachelement == 5:
			zero[4] += 1
		elif eachelement == 6:
			zero[5] += 1
	if zero not in no_repeats:
		no_repeats.append(zero)
#print(counter)
print(len(no_repeats))



	
