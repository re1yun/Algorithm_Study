import timeit

def knapsack(n, loads):
    '''
    Return the max sum of values that fit a knapsack with size n
    Input:
        n -- size of the knapsack
        loads -- list of 3-tuples, where each element is a 3-tuple (name, size, value), representing one load
            for example, [('A',2,10),('B',3,7)] indicates two loads, 
                (i) 'A' with size 2 and value 10
                (ii) 'B' with size 3 and value 7.
    '''
    assert type(n) == int, f"n = {n} must be an integer"
    assert n>=0 and n<=1000, f"n={n} must be >=0 and <=1000"
    assert type(loads) == list, f"type of loads ({type(loads)}) is not list"
    for e in loads:
        assert type(e) == tuple and len(e)==3, f"element in loads ({e}) must be a 3-tuple"
        assert type(e[1]) == int and type(e[2]) == int, f"element in loads ({e}) must be a 3-tuple with 2nd and 3rd value integers"
        assert e[1]>0 and e[2]>0, f"the size and value ({e[1]},{e[2]}) must be >0"

    '''
    Write your codes below
    '''

    # define a variable to store best value per size
    best = [0] * (n+1)

    # define a variable to store the minimum size
    min_size = n + 1

    # loop through each load and save the best value for each size
    for e in loads:
        min_size = min(min_size, e[1])
        if(e[1] > n):
            continue
        best[e[1]] = e[2]

    # if min_size is larger than n, return 0
    if(min_size > n):
        return 0
    
    # loop through each size and save the best value for each size
    for i in range(min_size, n + 1):
        # from min_size till i, find the best value
        for e in range(min_size, i):
            if(best[i] < best[e] + best[i-e]):
                best[i] = best[e] + best[i-e]

    return best[n]

def handshake(n):
    '''
    Return the number of ways to pair 2n vertices around a circle, such that the lines connecting pairs do not cross one another
    Input:
        n -- number of vertices
    '''
    assert type(n) == int, "n = {n} must be an integer"
    assert n>=0 and n<=100, f"n={n} must be >=0 and <=100"

    '''
    Write your codes below
    '''
    
    if(n == 0):
        return 1
    elif(n == 1):
        return 1
    elif(n == 2):
        return 2
    # define a variable to store the number of ways to pair 2n vertices
    ways = [0] * (n + 1)
    ways[0] = 1
    ways[1] = 1
    ways[2] = 2
    for num in range(3, n + 1):
        ways[num] = ways[num - 1] * 2
        for i in range(1, num - 1):
            ways[num] += ways[i] * ways[num - i - 1]
    return ways[n]


if __name__ == "__main__":
    print("Correctness test for knapsack()")
    correct = True

    # simple case where there is one possible item
    if knapsack(4, [('A',5,10)]) == 0: print("P ", end='') # no item can fit, since knapsack size < item size
    else: 
        print("F ", end='')
        correct = False

    if knapsack(9, [('A',5,10)]) == 10: print("P ", end='') # a single A is the max possible for the knapsack of size 9
    else: 
        print("F ", end='')
        correct = False

    # 4 items as shown in the lecture slides
    if knapsack(2, [('A',6,30),('B',4,16),('C',3,13),('D',2,9)]) == 9: print("P ", end='')
    else: 
        print("F ", end='')
        correct = False

    if knapsack(4, [('A',6,30),('B',4,16),('C',3,13),('D',2,9)]) == 18: print("P ", end='')
    else: 
        print("F ", end='')
        correct = False

    if knapsack(7, [('A',6,30),('B',4,16),('C',3,13),('D',2,9)]) == 31: print("P ", end='')
    else: 
        print("F ", end='')
        correct = False

    if knapsack(9, [('A',6,30),('B',4,16),('C',3,13),('D',2,9)]) == 43: print("P ", end='')
    else: 
        print("F ", end='')
        correct = False

    if knapsack(19, [('A',6,30),('B',4,16),('C',3,13),('D',2,9)]) == 91: print("P ", end='')
    else: 
        print("F ", end='')
        correct = False

    if knapsack(13, [('A',6,30),('B',4,16),('C',3,13),('D',2,9)]) == 61: print("P ", end='')
    else: 
        print("F ", end='')
        correct = False

    # 1 copy of item 2 and 1 copy of item 4 lead to a total value of 1*40 + 1*70 = 110
    if knapsack(8, [('item 1',1,10),('item 2',3,40),('item 3',4,50),('item 4',5,70)]) == 110: print("P ", end='')
    else: 
        print("F ", end='')
        correct = False

    # 6 copies of item 4 and 1 copy of item 5 lead to a total value of 6*50 + 1*10 = 310
    if knapsack(20, [('item 1',5,10),('item 2',4,40),('item 3',6,30),('item 4',3,50),('item 5',2,10)]) == 310: print("P ", end='')
    else: 
        print("F ", end='')
        correct = False
    
    print()
    print()
    print("Speed test for knapsack()")
    print("    if the test runs for more than 1 second, then you fail,")
    print("    so stop the test and consider using 'memoization' in your code")
    if not correct: print("fail (since the algorithm is not correct)")
    else:        
        n = 100
        tKnapsack = timeit.timeit(lambda: knapsack(1000, [('A',6,30),('B',4,16),('C',3,13),('D',2,9)]), number=n)/n        
        print(f"Average running time for knapsack ({tKnapsack:.10f})")        
        print("pass")        
    print()
    

    print("Correctness test for handshake()")
    correct = True

    if handshake(0) == 1: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False

    if handshake(1) == 1: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False
    
    if handshake(2) == 2: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False

    if handshake(3) == 5: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False
    
    if handshake(4) == 14: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False
    
    if handshake(5) == 42: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False

    if handshake(6) == 132: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False
    
    if handshake(7) == 429: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False

    if handshake(8) == 1430: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False
    
    if handshake(15) == 9694845: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False

    if handshake(99) == 227508830794229349661819540395688853956041682601541047340: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False
    
    if handshake(100) == 896519947090131496687170070074100632420837521538745909320: print("P ", end='') 
    else: 
        print("F ", end='')
        correct = False

    print()
    print()
    print("Speed test for handshake()")
    print("    if the test runs for more than 1 second, then you fail,")
    print("    so stop the test and consider using 'memoization' in your code")
    if not correct: print("fail (since the algorithm is not correct)")
    else:        
        n = 100
        tHandshake = timeit.timeit(lambda: handshake(100), number=n)/n        
        print(f"Average running time for handshake ({tHandshake:.10f})")        
        print("pass")        
    print()