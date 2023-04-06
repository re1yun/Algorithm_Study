import timeit
import math

def printSequence(product, depth, sequence):
        print(f"{product} = ", end='')
        for i in range(depth+1):
            print(sequence[i],end='')
            if i<depth: print("*",end='')
        print()

def findAllSequenceDiv(N, smallestFactor, print2stdout):
    def recur(n, initial_i, depth):
        for i in range(initial_i, n+1):
            if n % i == 0:
                sequence[depth] = i
                if n == i:
                    if print2stdout: printSequence(dividend, depth, sequence)
                else: recur(int(n/i), i, depth+1)
                
    sequence = [0 for i in range(N)]
    for dividend in range(smallestFactor, N+1):        
        recur(dividend, smallestFactor, 0)

def findAllSequenceDivSqrt(N, smallestFactor, print2stdout):
    def recur(n, initial_i, depth):
        for i in range(initial_i, int(math.sqrt(n))+1):
            if n % i == 0:
                sequence[depth] = i
                recur(int(n/i), i, depth+1)
        sequence[depth] = n
        if print2stdout: printSequence(dividend, depth, sequence)
                
    sequence = [0 for i in range(N)]
    for dividend in range(smallestFactor, N+1):        
        recur(dividend, smallestFactor, 0)

def findAllSequenceMult(N, smallestFactor, print2stdout):
    def recur(n, initial_i, product, depth):
        i = initial_i
        while product*i <= n:
            sequence[depth] = i
            if print2stdout: printSequence(product*i, depth, sequence)
            recur(n, i, product*i, depth+1)
            i += 1

    sequence = [0 for i in range(N)]
    recur(N, smallestFactor, 1, 0)    


def findDivisors(n):
    result = []
    for i in range(1, n+1):
        if n % i == 0:
            result.append(i)

    return result


def findNstoreCycle(elements, f):
    def recur(a):
        if result[a] != None: return -1

        if a in dictionary: return a
        else:
            dictionary[a] = len(dictionary)
            firstElementInCycle = recur(f[a])
            if firstElementInCycle == -1: # no cycle found that includes a
                result[a] = -1
                return -1
            else:
                result[a] = f[a]
                if a == firstElementInCycle:
                    cycleElements.append(a)
                    return -1
                else: return firstElementInCycle

    result = [None for _ in range(len(elements))]    
    dictionary = {}
    cycleElements = []
    for e in elements:
        dictionary.clear()
        recur(e)

    return cycleElements


if __name__ == "__main__":
    # observe output of findAllSequence()    
    findAllSequenceDiv(12, 2, True)
    print()
    findAllSequenceDivSqrt(12, 2, True)
    print()
    findAllSequenceMult(12, 2, True)    

    # measure execution time of findAllSequence()
    repeat = 10
    findAllSequence = findAllSequenceDiv
    tfindAllSequence = timeit.timeit(lambda: findAllSequence(1000, 2, False), number=repeat)/repeat    
    print(f"Average running time for findAllSequence is {tfindAllSequence:.10f}") 

    # find all divisors
    print(findDivisors(100))
    
    # find cycles among elements
    print(findNstoreCycle([0,1,2,3,4,5,6,7,8,9,10], [0,0,5,1,3,6,8,1,2,4,5]))    
