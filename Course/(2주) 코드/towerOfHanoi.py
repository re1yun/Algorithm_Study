def hanoi(n, fromPeg, viaPeg, toPeg):        
    if n==0: pass
    else:
        hanoi(n-1, fromPeg, toPeg, viaPeg) # move n-1 disks except the largest on the bottom to the via peg
        print(f"{fromPeg} -> {toPeg}") # move the largest disk to the to peg
        hanoi(n-1, viaPeg, fromPeg, toPeg) # move n-1 disks except the largest on the bottom to the to peg

if __name__ == "__main__":
    hanoi(6, 'A', 'B', 'C')