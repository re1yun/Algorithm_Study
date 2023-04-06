import math
import timeit
import random

def createProductSumSequence(sequence, maxIndex):
    '''
    Create a product-sum string given a sequence of numbers (e.g., createProductSumSequence([2,3], 2) --> '6=1*2*3=1+2+3')

    Input:
        sequence -- list of integers
        maxIndex -- maximum index to use for sequence (i.e., sequence[0] ~ sequence[maxIndex] are used to create the string)
    '''
    result = []

    product = 1
    sum = 0
    for i in range(maxIndex+1): 
        product *= sequence[i]
        sum += sequence[i]

    result.append(f"{product}=")
    for i in range(product-sum): result.append("1*")
    for i in range(maxIndex+1):
        result.append(str(sequence[i]))            
        if i<maxIndex: result.append("*")
    result.append("=")
    for i in range(product-sum): result.append("1+")
    for i in range(maxIndex+1):
        result.append(str(sequence[i]))            
        if i<maxIndex: result.append("+")

    return ''.join(result)


def findProductSum(n):
    '''
    Find all product-sum numbers within 2~n
    '''    
    # recur: recursive function to find all product-sum numbers
    def recur(product, sum, depth):
        i = 2
        while product * i <= n and sum + i <= n:
            sequence[depth] = i
            if(product * i >= sum + i and depth >= 1):
                temp = []
                temp.append(createProductSumSequence(sorted(sequence[ : depth + 1]), depth))
                # check if the product sum sequence is already in the answer
                check = True
                for j in answer:
                    if j == temp[0]:
                        check = False
                        break
                if check == True:
                    answer.extend(temp)
            recur(product * i, sum + i, depth+1)
            i += 1
    # answer: list of product-sum numbers
    answer = []
    # find all product-sum numbers within 2~n
    sequence = [0 for _ in range(n)]
    # sum: sum of numbers in sequence
    sum = 0
    # product: product of numbers in sequence
    product = 1
    # depth: current depth in the recursion tree
    depth = 0
    recur(product, sum, depth)
    return answer


def findMinimalProductSum(n):
    '''
    Find all a minimal product number for each k in 2<=k<=n
    '''
    # find minimal product-sum number for each k in 2<=k<=n
    result = {}
    # recur: recursive function to find all product-sum numbers
    def recur(min, product, sum, depth):
        i = min
        # iterate through n^2 in order to find all product-sum numbers until n
        while product * i <= n ** 2 and sum + i <= n ** 2:
            # if the product-sum number is found, see if it is minimal in k index
            if(product * i >= sum + i and depth >= 1):
                k = depth + 1 + (product * i) - (sum + i)
                # if number of index(k) is greater than n, we don't need it
                if(k > n):
                    break
                if(k not in result or result[k] > product * i):
                    result[k] = product * i
            recur(i, product * i, sum + i, depth+1)
            i += 1
    # answer: list of product-sum numbers
    answer = []
    # sum: sum of numbers in sequence
    sum = 0
    # product: product of numbers in sequence
    product = 1
    # depth: current depth in the recursion tree
    depth = 0
    recur(2, product, sum, depth)

    for i in range(2, n+1):
        answer.append(result[i])
    return answer


def findMinimalProductSumDivision(n):
    '''
    Find all product-sum numbers within 2~n, using a division tree
    This function is used to evaluate the execution time of findProductSum()
    '''
    def recur(min, number, currentSum, depth):
        for i in range(min, number+1):
            if number % i == 0:
                sequence[depth] = i
                if depth>=1 and number == i:                    
                    numFactors = depth + 1 + dividend - (currentSum+i)
                    if numFactors not in dictionary: dictionary[numFactors] = dividend                    
                recur(i, int(number/i), currentSum+i, depth+1)

    assert type(n)==int and n > 0, f"n={n} must be an integer greater than 0"    
    maxProduct = n**2
    sequence = [0 for _ in range(maxProduct)]
    dictionary = {}   # (key,value) = (# of factors (k), minimal product-sum number found so far)
    for dividend in range(2, maxProduct+1):
        recur(2, dividend, 0, 0)

    result = []    
    for i in range(2,n+1):
        result.append(dictionary[i])
    return result


if __name__ == "__main__":
    print("Correctness test for findProductSum()")
    correct = True

    if sorted(findProductSum(4)) == sorted(['4=2*2=2+2']): print("P ", end='')
    else:
        print("F ", end='')
        correct = False
    
    if sorted(findProductSum(6)) == sorted(['4=2*2=2+2', '6=1*2*3=1+2+3']): print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if sorted(findProductSum(9)) == sorted(['4=2*2=2+2', '8=1*1*2*2*2=1+1+2+2+2', '6=1*2*3=1+2+3', '8=1*1*2*4=1+1+2+4', '9=1*1*1*3*3=1+1+1+3+3']): print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if sorted(findProductSum(12)) == sorted(['4=2*2=2+2', '8=1*1*2*2*2=1+1+2+2+2', '12=1*1*1*1*1*2*2*3=1+1+1+1+1+2+2+3', '6=1*2*3=1+2+3', '8=1*1*2*4=1+1+2+4',\
                              '10=1*1*1*2*5=1+1+1+2+5', '12=1*1*1*1*2*6=1+1+1+1+2+6', '9=1*1*1*3*3=1+1+1+3+3', '12=1*1*1*1*1*3*4=1+1+1+1+1+3+4']): print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if sorted(findProductSum(16)) == sorted(['4=2*2=2+2', '8=1*1*2*2*2=1+1+2+2+2', '16=1*1*1*1*1*1*1*1*2*2*2*2=1+1+1+1+1+1+1+1+2+2+2+2',\
                              '12=1*1*1*1*1*2*2*3=1+1+1+1+1+2+2+3', '16=1*1*1*1*1*1*1*1*2*2*4=1+1+1+1+1+1+1+1+2+2+4', '6=1*2*3=1+2+3',\
                                 '8=1*1*2*4=1+1+2+4', '10=1*1*1*2*5=1+1+1+2+5', '12=1*1*1*1*2*6=1+1+1+1+2+6', '14=1*1*1*1*1*2*7=1+1+1+1+1+2+7',\
                                    '16=1*1*1*1*1*1*2*8=1+1+1+1+1+1+2+8', '9=1*1*1*3*3=1+1+1+3+3', '12=1*1*1*1*1*3*4=1+1+1+1+1+3+4',\
                                         '15=1*1*1*1*1*1*1*3*5=1+1+1+1+1+1+1+3+5', '16=1*1*1*1*1*1*1*1*4*4=1+1+1+1+1+1+1+1+4+4']): print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    print()
    print()

    print("Correctness test for findMinimalProductSum()")
    correct = True
    for i in range(10):
        n = random.randint(2,40)
        if findMinimalProductSum(n) == findMinimalProductSumDivision(n): print("P ", end='')
        else:
            print("F ", end='')
            correct = False
            print(f"findMinimalProductSum({n}) differs from findMinimalProductSumDivision({n})")
            print(f"findMinimalProductSum({n}): {findMinimalProductSum(n)}")
            print(f"findMinimalProductSumDivision({n}): {findMinimalProductSumDivision(n)}")
            print()

    print()
    print()
    print("Speed test for findMinimalProductSum()")
    if not correct: print("fail (since the algorithm is not correct)")
    else:        
        n = 100
        tSubmittedCode = timeit.timeit(lambda: findMinimalProductSum(10), number=n)/n        
        tDivSqrt = timeit.timeit(lambda: findMinimalProductSumDivision(10), number=n)/n        
        print(f"Average running time for the submitted code ({tSubmittedCode:.10f}) and the code based on division ({tDivSqrt:.10f})")        
        if tSubmittedCode*3 < tDivSqrt: print("pass")
        else: print("fail")
    print()
