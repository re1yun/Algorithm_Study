import math
import timeit


def findLongestAmicableChain(n):
    def findSarrayMultSqrt(n):
        for a in range(2, n + 1): 
            s[a] = 1
        for n1 in range(2, int(math.sqrt(n)) + 1):
            for n2 in range(n1, int(n / n1) + 1):
                s[n1 * n2] += n1
                if n2 != n1: s[n1 * n2] += n2

    # find longest chain
    def recur(a):
        if a > n: return -1
        # if s[a] is smaller than 1, or a is already in a cycle, should return -1
        if result[a] != None or s[a] < 1: return -1

        if a in chain: return a
        else:
            # add a to chain
            chain[a] = len(chain)
            firstElementInCycle = recur(s[a])
            if firstElementInCycle == -1: # no cycle found that includes a
                result[a] = -1
                return -1
            else:
                result[a] = s[a]
                # cycle found
                if a == firstElementInCycle:
                    # modify chain to store the cycle
                    # !! A -> B -> C -> D -> C 의 경우, chain = {A:0, B:1, C:2, D:3} 이므로, C를 찾아서, C부터 D까지만을 chain으로 만들어야 함
                    # nchain: new chain
                    nchain = []
                    check = False
                    for key in chain:
                        if check:
                            nchain.append(key)
                        if chain[key] == chain[a]:
                            check = True
                            nchain.append(key)
                    # update longestChain
                    if len(nchain) > len(longestChain):
                        longestChain.clear()
                        longestChain.extend(nchain)
                    # else if chain and longestChain have the same length, compare lowest number in chain and longestChain
                    elif len(nchain) == len(longestChain) and len(nchain) > 0:
                        if min(nchain) < min(longestChain):
                            longestChain.clear()
                            longestChain.extend(nchain)
                    return -1
                else:
                    return firstElementInCycle
    # define s
    s = [0 for _ in range(n + 1)]
    s[0] = 0
    s[1] = 0
    findSarrayMultSqrt(n)

    
    
    result = [None for _ in range(n + 1)]
    chain = {}
    longestChain = []
    for a in range(2, n + 1):
        chain.clear()
        recur(a)
    return longestChain


def findSarrayDivSqrt(n):
    '''
    Find s[] array for a=0~n
    This function is used to evaluate the execution time of findLongestAmicableChain()
    '''
    s = [0 for _ in range(n+1)]
    for a in range(2,n+1):
        for i in range(1, int(math.sqrt(a))+1):
            if a % i == 0:
                s[a] += i
                tmp = int(a/i)
                if tmp != i and tmp != a: s[a] += tmp
    return s


if __name__ == "__main__":
    print("Correctness test for findLongestAmicableChain()")
    correct = True

    if sorted(findLongestAmicableChain(10)) == sorted([6]): print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if sorted(findLongestAmicableChain(100)) == sorted([6]): print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if sorted(findLongestAmicableChain(1000)) == sorted([220,284]): print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if sorted(findLongestAmicableChain(10000)) == sorted([220,284]): print("P ", end='')
    else:
        print("F ", end='')
        correct = False

    if sorted(findLongestAmicableChain(100000)) == sorted([12496, 14288, 15472, 14536, 14264]): print("P ", end='')
    else:
        print("F ", end='')
        correct = False
    
    if sorted(findLongestAmicableChain(1000000)) == sorted([14316, 19116, 31704, 47616, 83328, 177792, 295488, 629072, 589786, 294896, 358336, 418904, 366556, 274924, 275444, 243760, 376736, 381028, 285778, 152990, 122410, 97946, 48976, 45946, 22976, 22744, 19916, 17716]): print("P ", end='')
    else:
        print("F ", end='')
        correct = False
    
    print()
    print()
    print("Speed test for findLongestAmicableChain()")
    if not correct: print("fail (since the algorithm is not correct)")
    else:
        n, repeat = 10000, 10   
        tSubmittedCode = timeit.timeit(lambda: findLongestAmicableChain(n), number=repeat)/repeat
        tDivSqrt = timeit.timeit(lambda: findSarrayDivSqrt(n), number=repeat)/repeat
        print(f"Average running time of the submitted code ({tSubmittedCode:.10f}) and of the code based on division ({tDivSqrt:.10f}) for n = {n}")
        if tSubmittedCode*2 < tDivSqrt: print("pass")
        else: print("fail")      
    print()