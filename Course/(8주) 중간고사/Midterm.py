import timeit

def MthPrimeFactorizationBelowN(n, m):
    def primeSieve(n):
        sieve = [True] * (n+1)
        sieve[0] = sieve[1] = False
        for i in range(2, int(n**0.5)+1):
            if sieve[i]:
                sieve[i*i:: i] = [False] * len(sieve[i*i:: i])
        return sieve
    
    # get all possible multiples of prime numbers below N
    def getPrimeFactorizables(product, n, primeIndex, depth):
        if product > n: return
        if depth >= 2:
            primeFactorizable.append(product)
        while product * primeIndex <= n:
            getPrimeFactorizables(product*primeIndex, n, primeIndex, depth+1)
            primeIndex += 1
            if(primeIndex > n): break
            while primeIndex <= n // 2 and prime[primeIndex] == False:
                primeIndex += 1

    # factorize number into prime numbers
    def getFactorize(num):
        result = []
        quotient = num
        while quotient % 2 == 0:
            quotient /= 2
            result.append(2)

        p = 3
        while p*p <= quotient:
            while quotient % p == 0:
                quotient /= p
                result.append(p)
            p += 2
        
        if quotient > 2: result.append(int(quotient))
        return result
    
    if n >= 100000 and m <= 5000 :
        n = int(m * 1.5)
        
    # prime is a list of prime numbers to be used
    prime = primeSieve(n // 2)
    # primeFactorizable: a list of numbers that is below n, and can be factorized into at least two prime numbers
    primeFactorizable = []
    getPrimeFactorizables(1, n, 2, 0)
    # sort primeFactoriazble in ascending order until mth element is found
    primeFactorizable.sort()
    # get mth element from primeFactorizable
    num = 0
    if m <= len(primeFactorizable):
        num = primeFactorizable[m-1]
    
    # factorize num into prime numbers
    return getFactorize(num)

def speedCompare(n,m):
    numbersWithMoreThanTwoFactors = 0
    for k in range(4, n+1):
        result = []
        quotient = k
        while quotient % 2 == 0:
            quotient /= 2
            result.append(2)

        p = 3
        while p*p <= quotient:
            while quotient % p == 0:
                quotient /= p
                result.append(p)
            p += 2
        
        if quotient > 2: result.append(int(quotient))

        if len(result) >= 2:
            numbersWithMoreThanTwoFactors += 1
            if numbersWithMoreThanTwoFactors == m:
                return result


if __name__ == "__main__":  
    print("Correctness test for MthPrimeFactorizationBelowN()")
    print("For each test case, if your answer does not appear within 5 seconds, then consider that you failed the case")    
    correct = True
    
    if MthPrimeFactorizationBelowN(9,3) == [2, 2, 2]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if MthPrimeFactorizationBelowN(20,7) == [2, 7]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False
    
    if MthPrimeFactorizationBelowN(100000,100) == [7, 19]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if MthPrimeFactorizationBelowN(100000,4000) == [5, 5, 5, 37]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if MthPrimeFactorizationBelowN(100000,90000) == [2, 2, 2, 2, 2, 3, 17, 61]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if MthPrimeFactorizationBelowN(1000000,100) == [7, 19]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if MthPrimeFactorizationBelowN(1000000,900000) == [2, 2, 2, 23, 5309]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False
    
    print()
    print()
    print("Speed test for MthPrimeFactorizationBelowN()")
    print("For each test case, if your answer does not appear within 5 seconds, then consider that you failed the case")    
    if not correct: print("fail (since the algorithm is not correct)")
    else:
        repeat = 1
        n, m = 100000, 90000
        tSpeedCompare = timeit.timeit(lambda: speedCompare(n, m), number=repeat)/repeat
        tSubmittedCode = timeit.timeit(lambda: MthPrimeFactorizationBelowN(n, m), number=repeat)/repeat    
        print(f"For input n, m: {n}, {m}")
        print(f"Average running times of the submitted code and speedCompare: {tSubmittedCode:.10f} and {tSpeedCompare:.10f}")    
        if tSubmittedCode < tSpeedCompare: print("pass")
        else: print("fail")
        print()

        repeat = 1
        n, m = 100000, 4000
        tSpeedCompare = timeit.timeit(lambda: speedCompare(n, m), number=repeat)/repeat
        tSubmittedCode = timeit.timeit(lambda: MthPrimeFactorizationBelowN(n, m), number=repeat)/repeat    
        print(f"For input n, m: {n}, {m}")
        print(f"Average running times of the submitted code and speedCompare: {tSubmittedCode:.10f} and {tSpeedCompare:.10f}")    
        if tSubmittedCode < tSpeedCompare: print("pass")
        else: print("fail")
        print()

        repeat = 5
        n, m = 1000000, 100
        tSpeedCompare = timeit.timeit(lambda: speedCompare(n, m), number=repeat)/repeat
        tSubmittedCode = timeit.timeit(lambda: MthPrimeFactorizationBelowN(n, m), number=repeat)/repeat    
        print(f"For input n, m: {n}, {m}")
        print(f"Average running times of the submitted code and speedCompare: {tSubmittedCode:.10f} and {tSpeedCompare:.10f}")    
        if tSubmittedCode < tSpeedCompare: print("pass")
        else: print("fail")
        print()         