#Austen Hsiao
#Program 1
#This program is a guessing game-- user input will be matched against a randomly chosen number. User gets 4 guesses before losing. Goodluck
import random #import module so we can generate a random number easily
user_guess_2 = 0
user_guess_3 = 0
user_guess_4 = 0
random.seed() #Initialize "random number"; No seed specified-- system time used instead
random_number= random.randint(1,20) #Generate a random number between 1 and 20 (inclusive)
print(random_number)
print("A random integer has been generated between 1-20, can you guess the correct value in four tries?")
user_guess_1= int(input("Please enter your first guess: ")) #Give a guess

##First Guess 
if user_guess_1 < random_number: print(user_guess_1, "is not correct. Your guess is less than the target value. \n")
elif user_guess_1 > random_number: print(user_guess_1, "is not correct. Your guess is greater than the target value. \n")
elif user_guess_1 == random_number: print("Congratulations, your guess of ", user_guess_1, "is correct!")

if user_guess_1 != random_number: 
    user_guess_2= int(input("You have 3 more chances. Enter your second guess: "))
    if user_guess_2 < random_number: print(user_guess_2, "is not correct. Your guess is less than the target value. \n")
    elif user_guess_2 > random_number: print(user_guess_2, "is not correct. Your guess is greater than the target value. \n")
    elif user_guess_2 == random_number: print("Congratulations, your guess of ", user_guess_2, "is correct!")

if user_guess_1 != random_number and user_guess_2 != random_number:
    user_guess_3= int(input("You have 2 more chances. Enter your third guess: "))
    if user_guess_3 < random_number: print(user_guess_3, "is not correct. Your guess is less than the target value. \n")
    elif user_guess_3 > random_number: print(user_guess_3, "is not correct. Your guess is greater than the target value. \n")
    elif user_guess_3 == random_number: print("Congratulations, your guess of ", user_guess_3, "is correct!")

if user_guess_1 != random_number and user_guess_2 != random_number and user_guess_3 != random_number:
    user_guess_4= int(input("You have 1 more chance. Enter your last guess: "))
    if user_guess_4 < random_number: print(user_guess_4, "is not correct. You have exhausted your number of guesses. \n")
    elif user_guess_4 > random_number: print(user_guess_4, "is not correct. You have exhausted your number of guesses. \n")
    elif user_guess_4 == random_number: print("Congratulations,", user_guess_4, "is correct!")
