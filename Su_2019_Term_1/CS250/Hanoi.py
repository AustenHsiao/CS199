import sys

# print out the disks for towers of hanoi
#
# Input stacks: the 3 stacks of disks
#               each stack contains the disks in reverse order
#               so the first element is the disk on the ground
#
# Input size: The height of the game.  This should be
#             at least as much as the total number of disks
def printHanoi(stacks, size):
    #split the stacks into individual lists
    [s1,s2,s3] = stacks
   
    # loop through the lists backwards, because they're in reverse order.
    for i in range(size)[::-1]:
        print(diskString(s1,i,size+2), "  ", end="")
        print(diskString(s2,i,size+2), "  ", end="")
        print(diskString(s3,i,size+2), "  ")

# gets a string for a disk.
# each disk is just a bunch of asterisks.
# so disk 3 is ***|***
# we add space to the disks so all the pegs line up.
#
# input peg: the stack of disks
# input i: which disk to print out form the stack
# input sp: the spacing between stack
#
# return: a string representing the disk with space around it.
def diskString(peg, i, sp):
    disk = 0
    if i < len(peg):
        disk = 2*peg[i]

    return " "*(sp-disk//2) + "*"*(disk//2) + "|" + "*"*(disk//2) + " "*(sp-disk//2)



# Moves disk x to the peg on the left (mod 3).
# If disk x isn't movable, then we give up and die.
# If disk x can move to the left, we try the peg on the right
# If it can't move to either peg, we give up and die.
#
# input stacks: the stacks of disks
# input x: the disk we want to move

# output: we don't return anything,
#         but stacks is modified so that the disk x has been moved legally.
def move(stacks, x):
    peg = -1
    # find the peg disk x is on top of.
    for i in range(len(stacks)):
        if len(stacks[i]) > 0 and stacks[i][-1] == x: peg = i

    # disk x isn't on top.
    # Well fine then, I'll just give up and die.
    if peg == -1:
        print("invalid move: disk", x ,"not on top")
        sys.exit(0)
  
    # peg on the left
    p1 = (peg+1) % 3
    # peg on the right
    p2 = (peg+2) % 3

    # if we can move to the left, do it.
    if   len(stacks[p1]) == 0 or stacks[p1][-1] > x:
        stacks[p1].append(stacks[peg].pop(-1))

    # if we can move to the right, do it.
    elif len(stacks[p2]) == 0 or stacks[p2][-1] > x:
        stacks[p2].append(stacks[peg].pop(-1))

    # We're stuck.  This is too hard, I'm giving up.
    else:
        print("invalid move: disk", x, "cannot be moved")
        sys.exit(0)

# This is the part you actually need to implement.
# right now we just move disk 1 a lot.
# It's technically a legal move, it's just not helpful.
def move_disk(i):
    return 1

# set up and run a ToH with a stack of 6 disks
def main():
    stacks = [[6,5,4,3,2,1],[],[]]
    printHanoi(stacks,6)
    for i in range(1,2**6):
        move(stacks,move_disk(i))
        print("after move", i)
        printHanoi(stacks,6)

