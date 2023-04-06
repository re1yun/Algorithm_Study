import timeit
import random


def findPrimes(maxN):
    '''
    Find all primes <= maxN and return them in a list
    '''
    prime = [True for _ in range(maxN+1)]
    prime[0] = prime[1] = False
    p = 2    
    while p*p <= maxN:
        if prime[p]:
            prime[p*p::p] = [False] * ((maxN - p*p) // p + 1)            
        p += 1

    result = []
    for i in range(len(prime)):
        if prime[i]: result.append(i)

    return result


def binarySearchEQ(numbers, target):
    '''
    Find target in the list numbers
    If the target exists in the list, return its index. Otherwise, return -1
    '''
    def recur(fromIndex, toIndex):
        if fromIndex > toIndex: return -1

        mid = int((fromIndex+toIndex)/2)        
        if numbers[mid] < target: return recur(mid+1, toIndex)
        elif numbers[mid] > target: return recur(fromIndex, mid-1)
        else: return mid

    return recur(0, len(numbers)-1) 


def variableLengthArguments(*args):
    print(f"args: {args}")    

    print(f"each item: ", end='')
    for arg in args: print(arg, end=' ')
    print()

    print(f"max(args): {max(args)}")


if __name__ == "__main__":
    print(findPrimes(100))

    n, repeat = 10000000, 1
    tFindPrimes = timeit.timeit(lambda: findPrimes(n), number=repeat)/repeat
    print(f"findPrimes({n}) took {tFindPrimes} seconds on average")

    print()    
    numbers = sorted([random.randint(0,30) for _ in range(20)])
    target = random.randint(0,30)
    print(f"Perform binary search to find {target} in list {numbers}")
    print(f"index of {target} is {binarySearchEQ(numbers, target)}")

    print()
    variableLengthArguments(1,2,3,4,5)
    print()
    variableLengthArguments(20,30,40)    