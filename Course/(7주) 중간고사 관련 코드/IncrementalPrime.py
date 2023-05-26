import timeit
import math


def findPrimes(maxN):
    return findPrimesIncrementally(maxN, [], [])

def findPrimesIncrementally(maxN, prime, result):
    '''
    Find all primes <= maxN using previously found prime[] and result[]    
    '''
    lastIndex = len(prime) - 1
    if lastIndex < maxN:
        prime.extend([True] * (maxN - lastIndex))
        if lastIndex < 0 and maxN >= 0: prime[0] = False
        if lastIndex < 1 and maxN >= 1: prime[1] = False
        p = 2
        while p*p <= maxN:
            if prime[p]:              
                # p * math.ceil((lastIndex + 1) / p):   the smallest integer index p * i that satisfies p * i >= lastIndex + 1
                firstIndex = max(p * p, p * math.ceil((lastIndex + 1) / p))
                prime[firstIndex::p] = [False] * ((maxN - firstIndex) // p + 1)            
            p += 1

        for i in range(lastIndex + 1, len(prime)):
            if prime[i]: result.append(i)

    return prime, result


if __name__ == "__main__":
    prime, result = findPrimes(10) # Find primes <= 10  
    prime, result = findPrimesIncrementally(20, prime, result) # Find primes <= 20, while reusing the previous results for <= 10
    print(prime, result)

    '''n1, n2, repeat = 100000, 200000, 10
    time1 = timeit.timeit(lambda: findPrimes(n1), number = repeat) / repeat
    prime, result = findPrimes(n1)
    time2 = timeit.timeit(lambda: findPrimesIncrementally(n2, prime, result), number = repeat) / repeat
    print(f"average running time for finding primes <= {n1} {time1:.5f} and then <= {n2} {time2:.5f}: {time1 + time2:.5f}")

    timeOnce = timeit.timeit(lambda: findPrimes(n2), number = repeat) / repeat
    print(f"average running time for finding primes <= {n2} at once {timeOnce:.5f}")    
    
    prime, result = findPrimes(n1)
    prime, result = findPrimesIncrementally(n2, prime, result)

    primeOnce, resultOnce = findPrimes(n2)
    if result == resultOnce: print("same")
    else: print("different") '''