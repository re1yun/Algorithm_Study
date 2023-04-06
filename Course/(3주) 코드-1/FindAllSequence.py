def findAllSequenceRecursion(maxSum, min, print2stdout):
    '''
    Find all integer sequences whose sums <= maxSum and each element >= min, using recursion
    '''
    def recur(currentSum, depth):
        i = min
        while currentSum+i <= maxSum:
            sequence[depth] = i
            if print2stdout: print(sequence[0:depth+1])         
            recur(currentSum+i, depth+1)
            i += 1
    
    assert maxSum > 0, f"maxSum={maxSum} must be greater than 0"
    assert min > 0, f"min={min} must be greater than 0"
    sequence = [0 for _ in range(maxSum)]
    recur(0, 0)

def findAllSequenceNoRecursion(maxSum, min, print2stdout):
    '''
    Find all integer sequences whose sums <= maxSum and each element >= min, without using recursion
    '''
    assert maxSum > 0, f"maxSum={maxSum} must be greater than 0"
    assert min > 0, f"min={min} must be greater than 0"

    sequence = [0 for _ in range(maxSum)]
    currentSum = [0 for _ in range(maxSum+1)] # currentSum in the stack
    i = [0 for _ in range(maxSum+1)] # i in the stack
    i[0] = min
    depth = 0

    while True:
        while currentSum[depth] + i[depth] > maxSum:
            depth -= 1
            if depth < 0: return
        sequence[depth] = i[depth]
        if print2stdout: print(sequence[0:depth+1])
        currentSum[depth+1] = currentSum[depth] + i[depth]        
        i[depth] += 1
        depth += 1
        #i[depth] = min
        i[depth] = i[depth - 1]        

from queue import Queue
def findAllSequenceBFS(maxSum, min, print2stdout):
    queue = Queue()
    queue.put((0, None, None)) # (sum, current element, reference to parent tuple)
    while queue.qsize() > 0:
        v = queue.get()
        if print2stdout:
            vUp = v
            while vUp[1] != None:
                print(vUp[1], end=' ') # print the element
                vUp = vUp[2] # move to the parent
            print()
        e = min
        while v[0]+e <= maxSum:
            queue.put((v[0]+e, e, v))
            e += 1

if __name__ == "__main__":    
    findAllSequenceRecursion(4, 2, True)
    print("리커전 던")
    findAllSequenceNoRecursion(6, 2, True)
    print("노 리커전 던")
    findAllSequenceBFS(6, 2, True)

    #findAllSequenceRecursion(2000, 2, False) # Error occurs if recursion depth >> 1,000    
    #findAllSequenceNoRecursion(2000, 2, False) 
    #findAllSequenceBFS(2000, 2, False)

    

