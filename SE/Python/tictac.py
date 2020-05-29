
board = [" " for x in range(10)]


def insert(letter,pos):
    board[pos] = letter


def printboard(board):
    print("     |     |     ")
    print(f"  {board[1]}  |  {board[2]}  |  {board[3]}  ")
    print("     |     |     ")
    print("-----------------")
    print("     |     |     ")
    print(f"  {board[4]}  |  {board[5]}  |  {board[6]}  ")
    print("     |     |     ")
    print("-----------------")
    print("     |     |     ")
    print(f"  {board[7]}  |  {board[8]}  |  {board[9]}  ")
    print("     |     |     ")


def spaceisfree(pos):
    return board[pos] == " "


def isboardfull(board):
    if board.count(" ") > 1:
        return False
    else:
        return True


def iswinner(b,l):
    return ((b[1]== l and b[2] == l and b[3] == l) or 
    (b[4] == l and b[5] == l and b[6] == l) or 
    (b[7] == l and b[8] == l and b[9] == l) or 
    (b[1] == l and b[4] == l and b[7] == l) or
    (b[2] == l and b[5] == l and b[8] == l) or
    (b[3] == l and b[6] == l and b[9] == l) or
    (b[1] == l and b[5] == l and b[9] == l) or
    (b[3] == l and b[5] == l and b[7] == l))


def playermove():
    run =True

    while(run):
        try:
            pi = int(input("Please enter the position for 'X' (1-9) : "))
            if pi > 0 and pi < 10 and spaceisfree(pi):
                run = False
                insert("X",pi)
            else:
                print("try Another Position")
        except:
            print("please type an integer")
        

def computermove():
    pm = [ x for x , letter in enumerate(board) if letter == " " or letter != "O"]
    move = 0

    for let in ["O","X"]:
        for i in pm:
            bc = board[:]
            bc[i] =let
            if iswinner(bc,let):
                move = i
                return move
    corner = []
    for i in pm:
        if i in [1,3,7,9]:
            corner.append(i)

    if len(corner) > 0:
        move = selectRandom(corner)
        return move
    
    if 5 in pm:
        move = 5
        return move

    edge = []
    for i in pm:
        if i in [2,4,6,8]:
            edge.append(i)
    if len(corner) > 0:
        move = selectRandom(edge)
        return move


def selectRandom(li):
    import random
    ln = len(li)
    l=random.randrange(ln)
    return li[l]


def main():
    print("welcome to the game")
    printboard(board)
    while not isboardfull(board):
        if not iswinner(board,'O'):
            playermove()
            printboard(board)
        else:
            print("You Lose !!")
            break

        if not iswinner(board,'X'):
            mov = computermove()
            if mov == 0:
                print(" ")
            else:
                insert("O",mov)
                print(f"computer placed at {mov}")
                printboard(board)
        else:
            print("you win !!")


while True:
    x = input("do u want to play again y/n")
    if x.lower() == "y":
        board = [" " for x in range(10)]
        main()
    else:
        break
