from os import system
from random import choice


def hangman():
    word = choice(["sumeet","rites","ram","koma"])
    vl = 'abcdefghijklmnopqrstuvwxyz'
    guessw = ''
    attempts = 10

    while(len(word)>0):
        main=""
        system("cls")
        for letter in word:
            if letter in guessw:
                main += letter
            else:
                main += " _ "

        if main == word:
            system("cls")
            print("the word is : ", main)
            print("You Won !!!")
            break

        print("Guess the Word : ",main)
        guess = input()


        if guess in vl:
            guessw += guess
        else:
            print("Enter valid character")
            guess = input()
        if guessw not in word:
            attempts-=1
            if attempts == 9:
                print("9 Attempt left")
                print("--------------")
                print("       O      ")
                print("              ")
                print("              ")
            elif attempts == 8:
                print("8 Attempt left")
                print("--------------")
                print("      O       ")
                print("      |       ")
                print("              ")
            elif attempts == 7:
                print("7 Attempt left")
                print("--------------")
                print("      O       ")
                print("      |       ")
                print("     /        ")
            elif attempts == 6:
                print("6 Attempt left")
                print("--------------")
                print("      O       ")
                print("      |      ")
                print("     / \      ")
            elif attempts == 5:
                print("5 Attempt left")
                print("--------------")
                print("      O       ")
                print("      |      ")
                print("     / \      ")
            elif attempts == 4:
                print("4 Attempt left")
                print("--------------")
                print("      O /     ")
                print("      |      ")
                print("     / \      ")
            elif attempts == 3:
                print("3 Attempt left")
                print("--------------")
                print("    \ O _     ")
                print("      |\      ")
                print("     / \      ")
            elif attempts == 2:
                print("2 Attempt left")
                print("--------------")
                print("      O_      ")
                print("     /|\      ")
                print("     / \      ")
            elif attempts == 1:
                print("1 Attempt left")
                print("--------------")
                print("      O__       ")
                print("     /|\      ")
                print("     / \      ")
            elif attempts == 0:
                print("You Killed a innocent one")
                print("--------------")
                print("      O__|     ")
                print("     /|\      ")
                print("     / \      ")
                break
            system("pause")


name = input("Enter Your Name : ")
system("cls")
print(f"WELCOME , {name}\n-----------------")
print(f"try to guess the word in 10 attempts")
hangman()



'''
Algorithm
Develope a interface
world list
instruction
check the word
    write then enter the list or else draw a fig

'''