import timeit


def findLongestConsecutivePrimeSum(*sums):   
    def findPrimes(maxSum):
        prime = [True for _ in range(maxSum + 1)]
        prime[0] = prime[1] = False
        p = 2    
        while p*p <= maxSum:
            if prime[p]:
                for i in range(p*p, maxSum + 1, p): prime[i] = False
            p += 1
        return prime

    def findPrimeSumFirstRow(maxSum, prime):
        primeSumFirstRow = []
        sum = 0    
        for p in range(maxSum):
            if prime[p]: 
                sum += p
                primeSumFirstRow.append(sum)
        return primeSumFirstRow
    
    def binarySearch(primeSumFirstRow, start, end, target):
        if start > end: return end
        mid = (start + end) // 2
        if primeSumFirstRow[mid] == target: return mid
        elif primeSumFirstRow[mid] > target: return binarySearch(primeSumFirstRow, start, mid-1, target)
        else: return binarySearch(primeSumFirstRow, mid+1, end, target)

    answer = []
    maxSum = max(sums)
    # prime: prime[i] = True if i is prime prime[i] = False if i is not
    prime = findPrimes(maxSum)
    # primeSumFirstRow = sum of consecutive primes where sn = 2
    primeSumFirstRow = findPrimeSumFirstRow(maxSum, prime)
    # primeSums = sum of consecutive primes for all sn and en (2d array)
    primeSums = [primeSumFirstRow]
    # iterate through sums
    for sum in sums:
        # rightBorder = index of largest primeSumFirstRow[i] which is smaller or equal to sum
        rightBorder = binarySearch(primeSumFirstRow, 0, len(primeSumFirstRow)-1, sum)
        leftBorder = 0
        row = 0
        resultSum = 0
        resultLength = 0
        while leftBorder < rightBorder:
            # iterate from bigest sum to lower sum
            for i in range(rightBorder, leftBorder, -1):
                # if the sum is prime, check if it is longest consecutive prime sum
                if(prime[primeSums[row][i]] == True):
                    # if it is longest consecutive prime sum, update result and proceed to next row
                    if(resultLength < i - leftBorder + 1):
                        resultSum = primeSums[row][i]
                        resultLength = i - leftBorder + 1
                        break
            row += 1
            leftBorder += 1
            # if primeSums does not have row yet, add row
            if(len(primeSums) <= row):
                primeSumCurrentRow = [0] * (len(primeSumFirstRow) + 1)
                for i in range(leftBorder, len(primeSumFirstRow)):
                    primeSumCurrentRow[i] = primeSums[0][i] - primeSums[0][leftBorder - 1]
                primeSums.append(primeSumCurrentRow)
            # update rightBorder and see if available longest consecutive prime sum is shorter than current result
            rightBorder = binarySearch(primeSums[row], leftBorder, len(primeSumCurrentRow), sum)
            # if available longest consecutive prime sum is shorter than current result, stop
            if(rightBorder - leftBorder + 1 < resultLength): break
        answer.append((resultSum, resultLength))
    return answer


def speedCompare1(*sums):
    '''
    Compute the entire 2D table in advance
    This function is used to evaluate the execution time of findLongestConsecutivePrimeSum()
    '''
    maxSum = max(sums)
    
    prime = [True for _ in range(maxSum)]
    prime[0] = prime[1] = False
    p = 2    
    while p*p <= maxSum:
        if prime[p]:
            for i in range(p*p, maxSum, p): prime[i] = False
        p += 1
    
    primeSumFirstRow = []
    sum = 0    
    for p in range(maxSum):
        if prime[p]: 
            sum += p
            primeSumFirstRow.append(sum)

    primeSums = [primeSumFirstRow]
    for row in range(1, len(primeSumFirstRow)):
        primeSumCurrentRow = []
        for i in range(len(primeSumFirstRow)):
            if i < row: primeSumCurrentRow.append(None)
            else: primeSumCurrentRow.append(primeSumFirstRow[i] - primeSumFirstRow[row-1])
        primeSums.append(primeSumCurrentRow)

def speedCompare2(*sums):
    '''
    Perform prime sieve for each N in sums
    This function is used to evaluate the execution time of findLongestConsecutivePrimeSum()
    '''
    for sum in sums:
        prime = [True for _ in range(sum)]
        prime[0] = prime[1] = False
        p = 2    
        while p*p <= sum:
            if prime[p]:
                for i in range(p*p, sum, p): prime[i] = False
            p += 1
        
        primeSumFirstRow = []
        sum = 0    
        for p in range(sum):
            if prime[p]: 
                sum += p
                primeSumFirstRow.append(sum)    


if __name__ == "__main__":
    print("Correctness test for findLongestConsecutivePrimeSum()")
    print("For each test case, if your answer does not appear within 5 seconds, then consider that you failed the case")
    correct = True

    if findLongestConsecutivePrimeSum(100,200,300) == [(41, 6), (197, 12), (281, 14)]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if findLongestConsecutivePrimeSum(500,600,700,800,900,1000) == [(499, 17), (499, 17), (499, 17), (499, 17), (857, 19), (953, 21)]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False
        
    if findLongestConsecutivePrimeSum(2000,5000,10000,20000,50000) == [(1583, 27), (4651, 45), (9521, 65), (16823, 81), (49279, 137)]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if findLongestConsecutivePrimeSum(60000,70000,80000,90000,100000) == [(55837, 146), (66463, 158), (78139, 167), (86453, 178), (92951, 183)]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if findLongestConsecutivePrimeSum(1000000,5000000,8000000) == [(997651, 543), (4975457, 1150), (7998491, 1433)]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if findLongestConsecutivePrimeSum(10000000) == [(9951191, 1587)]: print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    print()
    print()
    print("Speed test for findLongestConsecutivePrimeSum()")
    if not correct: print("fail (since the algorithm is not correct)")
    else:
        repeat = 10
        sums = [5000]
        tSpeedCompare1 = timeit.timeit(lambda: speedCompare1(*sums), number=repeat)/repeat
        tSubmittedCode = timeit.timeit(lambda: findLongestConsecutivePrimeSum(*sums), number=repeat)/repeat    
        print(f"For input sums: {sums}")
        print(f"Average running times of the submitted code and the code that computes the entire 2D table in advance: {tSubmittedCode:.10f} and {tSpeedCompare1:.10f}")    
        if tSubmittedCode < tSpeedCompare1: print("pass")
        else: print("fail")
        print()

        sums = [10000,20000,30000,40000,50000,60000,70000,80000,90000]
        tSpeedCompare2 = timeit.timeit(lambda: speedCompare2(*sums), number=repeat)/repeat
        tSubmittedCode = timeit.timeit(lambda: findLongestConsecutivePrimeSum(*sums), number=repeat)/repeat    
        print(f"For input sums: {sums}")
        print(f"Average running times of the submitted code and the code that performs sieve for each sum in sums: {tSubmittedCode:.10f} and {tSpeedCompare2:.10f}")
        if tSubmittedCode < tSpeedCompare2: print("pass")
        else: print("fail")
    

    

