#Pig latin translator
#Austen Hsiao
from pig_latin import is_vowel, is_consonant, is_punc
 
user = input("Enter a string: ")
translated = []
english = user.split() #split the sentence into words as each element in 'english'
size = len(english) 
n = 0

for each_word in english: #iterate through each word in list 'english'. I tried to do this with a while loop but it was so confusing, I gave up to use this instead
	n = 1 #set n = 1 so the the block for consonants will iterate properly. The first letter is removed, so we want to use the 1st element (not the 0th)


##VOWELS
	if is_vowel(each_word[0]): #if the first letter of the word is a vowel, 
		if is_punc(each_word[len(each_word)-1]): #if it has punctuation on the end of it 
			translated.append(each_word[:-1]) #add the word to the list minus the punctuation
			translated.append('ay') #add 'ay' to the word to make it pig latin
			translated.append(each_word[len(each_word)-1]) #now add on the punctuation
			translated.append(' ') #need to add a space for the next word
		
		else: #if it doesn't have punctuation on the end of it
			translated.append(each_word) #add the word to the list
			translated.append('ay ') #add 'ay' to the word to make it pig latin

##CONSONANTS			
	elif is_consonant(each_word[0]):
		if is_punc(each_word[len(each_word)-1]): #check behind each word for punctuation. It does not make sense to have punctuation before the word, so I don't check for this scenario		
			if each_word[0].isupper(): #if the first letter of the word is a capital consonant, 
				translated.append(each_word[1].upper()) #add the second letter and capitalize it
			else: 
				translated.append(each_word[1]) #otherwise, just append the second letter 
			while n < len(each_word) - 2: #for the length of the word minus 1 (so -2)
				translated.append(each_word[n+1]) #add the 3rd letter
				n += 1 #plus one and redo this block
			translated.append(each_word[0].lower())
			translated.append('ay')
			translated.append(each_word[len(each_word)-1]) #add on the punctuation
			translated.append(' ') #add space

		else:	#No punctuation on the end of it
			if each_word[0].isupper(): 
				translated.append(each_word[1].upper())
			else: 
				translated.append(each_word[1]) 
			while n < len(each_word) - 1: #Go to the end of the word
				translated.append(each_word[n+1])
				n += 1
			translated.append(each_word[0].lower())
			translated.append('ay ')
	
	else: #for all other sentences whose words begin with a something other than an alphabetic character
		print("Not sure how to convert this to pig latin")

print(''.join(translated)) #Put it all together
