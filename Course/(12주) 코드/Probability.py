import math
import timeit
from pathlib import Path


def monopoly(numSides, numIterations):
    squares = ["GO","A1","CC1","A2","T1","R1","B1","CH1","B2","B3",\
                   "JAIL","C1","U1","C2","C3","R2","D1","CC2","D2","D3",\
                   "FP","E1","CH2","E2","E3","R3","F1","F2","U2","F3",\
                   "G2J","G1","G2","CC3","G3","R4","CH3","H1","T2","H2"]
    
    probCurrent = [0 for _ in range(len(squares))]
    probCurrent[0] = 1 # game begins from "GO"
    probTransition = []
    bot = math.pow(numSides, 2)
    for sx in range(len(squares)):
        probTransitionSx = [0 for _ in range(len(squares))]
        for n in range(2, numSides * 2 + 1):
            sy = (sx + n) % len(squares)
            if n <= numSides:
                top = n - 1
            else:
                top = 2 * numSides + 1 - n
            # if arriving at "G2J", go to "JAIL"
            if sy == 30:
                probTransitionSx[10] += (top / bot)
            # if arriving at "CC1", "CC2", or "CC3", go to "GO" by 1/16 probability, go to "JAIL" by 1/16 probability, and stay at the current square by 14/16 probability
            elif sy == 2 or sy == 17 or sy == 33:
                probTransitionSx[0] += (top / bot * (1.0/16.0))
                probTransitionSx[10] += (top / bot * (1.0/16.0))
                probTransitionSx[sy] += (top / bot * (14.0/16.0))
            # if arriving at "CH1", "CH2", or "CH3", go to "GO" by 1/16 probability, go to "JAIL" by 1/16 probability, go to "C1" by 1/16 probability, go to "E3" by 1/16 probability, go to "H2" by 1/16 probability, go to "R1" by 1/16 probability, go to the next railway company by 2/16 probability, go to the next utility company by 1/16 probability, go to three step back by 1/16 probability, and stay at the current square by 6/16 probability
            elif sy == 7 or sy == 22 or sy == 36:
                probTransitionSx[0] += (top / bot * (1.0/16.0))
                probTransitionSx[10] += (top / bot * (1.0/16.0))
                probTransitionSx[11] += (top / bot * (1.0/16.0))
                probTransitionSx[24] += (top / bot * (1.0/16.0))
                probTransitionSx[39] += (top / bot * (1.0/16.0))
                probTransitionSx[5] += (top / bot * (1.0/16.0))
                probTransitionSx[sy] += (top / bot * (6.0/16.0))
                if sy == 7:
                    probTransitionSx[15] += (top / bot * (2.0/16.0))
                    probTransitionSx[12] += (top / bot * (1.0/16.0))
                    probTransitionSx[sy - 3] += (top / bot * (1.0/16.0))
                elif sy == 22:
                    probTransitionSx[25] += (top / bot * (2.0/16.0))
                    probTransitionSx[28] += (top / bot * (1.0/16.0))
                    probTransitionSx[sy - 3] += (top / bot * (1.0/16.0))
                elif sy == 36:
                    probTransitionSx[5] += (top / bot * (2.0/16.0))
                    probTransitionSx[12] += (top / bot * (1.0/16.0))
                    probTransitionSx[sy - 3] += (top / bot * (1.0/16.0) * 14.0/16.0)
                    probTransitionSx[0] += (top / bot * (1.0/16.0) * 1.0/16.0)
                    probTransitionSx[10] += (top / bot * (1.0/16.0) * 1.0/16.0)
            else:
                probTransitionSx[sy] += (top / bot)
        probTransition.append(probTransitionSx)

    # for each turn
    for i in range(numIterations):
        # calculate probability of arriving at each square
        probNext = [0 for _ in range(len(probCurrent))]
        # iterate through 0 till 39, which is the index of each square
        for sx in range(len(squares)):
            if probCurrent[sx] != 0:
                for sy in range(len(squares)):
                    probNext[sy] += probTransition[sx][sy] * probCurrent[sx]
        probCurrent = probNext
        
    return [(squares[square], probCurrent[square]) for square in range(len(squares))]


def simpleGame(numSquares, numSides, numIterations, debug):
    '''
    Run a simple monopoly game with no exceptional rules and compute the probability of landing in each square

    Input:
        numSquare: # of squares in the game
        numSides: # of sides of a die
        numIterations: # of die rolls
        debug: if True, print probabilities at the end of each iteration

    Return value: list containing probabilities of landing in the squares
    '''    
    probCurrent = [0 for _ in range(numSquares)]
    probCurrent[0] = 1 # game begins from square 0
    probTransition = []
    for sx in range(numSquares):
        probTransitionSx = [0 for _ in range(numSquares)]
        for n in range(1, numSides + 1):
            probTransitionSx[(sx + n) % numSquares] += 1 / numSides
        probTransition.append(probTransitionSx)    

    for i in range(numIterations):
        probNext = [0 for _ in range(len(probCurrent))]
        for sx in range(len(probTransition)):
            for sy in range(len(probTransition[sx])):
                probNext[sy] += probTransition[sx][sy] * probCurrent[sx]
        probCurrent = probNext
        if debug: print(probCurrent)

    return probCurrent


if __name__ == "__main__":
    '''
    Test for in-class problems
    '''
    # Run a simple game with no exceptional rules
    # simpleGame(numSquares, numSides, numIterations, debug)
    #simpleGame(2, 2, 10, True)

    '''
    Test for after-class problems
    '''
    #numSides, numIterations = 2, 1
    #print(monopoly(numSides, numIterations))
    #'''
    print()
    print("Correctness test for monopoly()")
    print(" for each case, if your answer does not appear within 2 seconds, consider that you failed the case")
    correct = True

    def equal(list1, list2):
        # Confirm that two result lists are equal up to the length of list2 
        # when sorted by probabilities in decreasing order
        # and then return differences in the two lists in string
        def equalFloat(float1, float2):
            # confirm that two floating-point numbers are equal up to 6 digits below dot
            return int(float1*1000000) == int(float2*1000000)
        list1 = sorted(list1, key=lambda x: (-x[1], x[0])) # sort lists in decreasing order of their probabilities and then by their names
        list2 = sorted(list2, key=lambda x: (-x[1], x[0]))
        differences = []
        i = 0
        while i < len(list1) and i < len(list2):
            if list1[i][0] == list2[i][0] and equalFloat(list1[i][1], list2[i][1]): pass
            else: differences.append(f"{list1[i]} != {list2[i]}")
            i += 1
        #for j in range(i, len(list1)): differences.append(f"{list1[j]} != nothing")
        for j in range(i, len(list2)): differences.append(f"nothing != {list2[j]}")
        return '\n'.join(differences)

    numSides, numIterations = 2, 1
    result = equal(monopoly(numSides, numIterations), [('A2', 2/4), ('T1', 1/4), ('CC1', 1/4*14/16), ('GO', 1/4*1/16), ('JAIL', 1/4*1/16)])
    if len(result) == 0: print("P ", end='')
    else:
        print(f"Fail with monopoly({numSides}, {numIterations}) for the following entries")
        print(result)
        correct = False

    numSides, numIterations = 2, 2
    result = equal(monopoly(numSides, numIterations), [('B1', 0.3671875), ('R1', 0.25), ('CH1', 0.09375), ('T1', 0.07421875), ('B2', 0.0625), ('R2', 0.03125), ('U1', 0.01953125), ('GO', 0.015869140625), ('JAIL', 0.015869140625), ('C1', 0.015625), ('E3', 0.015625), ('H2', 0.015625), ('A2', 0.0078125), ('C2', 0.0078125), ('C3', 0.00390625), ('CC1', 0.00341796875)])
    if len(result) == 0: print("P ", end='')
    else:
        print(f"Fail with monopoly({numSides}, {numIterations}) for the following entries")
        print(result)
        correct = False

    numSides, numIterations = 6, 1
    result = equal(monopoly(numSides, numIterations), [("GO", 6/36*1/16+1/36*1/16), ("A1", 0), ("CC1", 1/36*14/16), ("A2", 2/36), ("T1", 3/36+6/36*1/16), ("R1", 4/36+6/36*1/16), ("B1", 5/36), ("CH1", 6/36*6/16), ("B2", 5/36), ("B3", 4/36),\
                   ("JAIL", 3/36+1/36*1/16+6/36*1/16), ("C1", 2/36+6/36*1/16), ("U1", 1/36+6/36*1/16), ("C2", 0), ("C3", 0), ("R2", 6/36*2/16), ("D1", 0), ("CC2", 0), ("D2", 0), ("D3", 0),\
                   ("FP", 0), ("E1", 0), ("CH2", 0), ("E2", 0), ("E3", 6/36*1/16), ("R3", 0), ("F1", 0), ("F2", 0), ("U2", 0), ("F3", 0),\
                   ("G2J", 0), ("G1", 0), ("G2", 0), ("CC3", 0), ("G3", 0), ("R4", 0), ("CH3", 0), ("H1", 0), ("T2", 0), ("H2", 6/36*1/16)])
    if len(result) == 0: print("P ", end='')
    else:
        print(f"Fail with monopoly({numSides}, {numIterations}) for the following entries")
        print(result)
        correct = False

    numSides, numIterations = 6, 2
    result = equal(monopoly(numSides, numIterations), [('R2', 0.10022424768518519), ('C3', 0.09910300925925926), ('C2', 0.09693287037037038), ('U1', 0.08967496141975309), ('D1', 0.08945794753086421), ('C1', 0.07736846547067902), ('JAIL', 0.0680892379195602), ('CC2', 0.06743103780864197), ('D2', 0.06196952160493827), ('D3', 0.04739643614969136), ('B3', 0.04398148148148148), ('FP', 0.03293788580246913), ('B2', 0.030815972222222217), ('E1', 0.02102623456790123), ('B1', 0.011140046296296294), ('R1', 0.007767288773148146), ('CH1', 0.007269965277777776), ('GO', 0.006987771870177469), ('E2', 0.006847993827160494), ('E3', 0.005416304976851851), ('CH2', 0.004864728009259259), ('T1', 0.004056954089506172), ('R3', 0.0033576871141975306), ('H2', 0.00204053337191358), ('G1', 0.001736111111111111), ('U2', 0.0016788435570987653), ('A2', 0.0015432098765432098), ('F1', 0.0014467592592592592), ('G2', 0.0014467592592592592), ('F2', 0.0011574074074074073), ('F3', 0.0011574074074074073), ('CC3', 0.0010285554108796296), ('G3', 8.680555555555555E-4), ('CC1', 8.017457561728394E-4), ('R4', 5.787037037037037E-4), ('A1', 2.8935185185185184E-4), ('CH3', 1.0850694444444444E-4)])
    if len(result) == 0: print("P ", end='')
    else:
        print(f"Fail with monopoly({numSides}, {numIterations}) for the following entries")
        print(result)
        correct = False

    numSides, numIterations = 3, 10
    result = equal(monopoly(numSides, numIterations), [('GO', 0.06104874257858372), ('H2', 0.055082763836255225), ('A1', 0.054553863755747674), ('A2', 0.05061250398066039), ('CC1', 0.04709661502375401), ('T2', 0.04664953227799694), ('H1', 0.04429253246473268), ('T1', 0.04260699205815242), ('R1', 0.04146387044975039), ('JAIL', 0.031747921156123626), ('D3', 0.03103669580634112), ('D2', 0.02918391293790386), ('FP', 0.02806942382508427), ('R4', 0.02697919085312381), ('E1', 0.026184285252536212), ('E3', 0.024849810659276408), ('B1', 0.024118418416134612), ('E2', 0.02387894666900277), ('R2', 0.0228194385117169), ('D1', 0.022453793146803232), ('CC2', 0.0215378915817451), ('C3', 0.02056372400198587), ('R3', 0.0180923406616637), ('G3', 0.01780470603155144), ('B2', 0.017043158104016746), ('CC3', 0.014666326132170681), ('B3', 0.014486657204239101), ('C2', 0.014326646839731023), ('CH3', 0.013281287579530015), ('U2', 0.01325095025457209), ('U1', 0.01276434058931714), ('G2', 0.012433373912183993), ('G1', 0.012030290951840186), ('C1', 0.01169207084218159), ('F1', 0.011554728168089404), ('F3', 0.011381397665291625), ('F2', 0.011285010400658548), ('CH2', 0.009619704392921324), ('CH1', 0.007456141026629724)])
    if len(result) == 0: print("P ", end='')
    else:
        print(f"Fail with monopoly({numSides}, {numIterations}) for the following entries")
        print(result)
        correct = False

    numSides, numIterations = 7, 100
    result = equal(monopoly(numSides, numIterations), [('JAIL', 0.05874424983243052), ('E3', 0.03186036037034319), ('GO', 0.03150434933006223), ('R1', 0.030518482019856248), ('D3', 0.030390358815102922), ('R3', 0.029872860907522707), ('D2', 0.0288267149458482), ('FP', 0.028359628173609038), ('E1', 0.028245102752490082), ('U2', 0.02822103865433986), ('R2', 0.027975323590455473), ('C1', 0.027938692684244686), ('E2', 0.027878321808575333), ('H2', 0.026877987640352218), ('U1', 0.026667878251873323), ('F2', 0.026526144007463753), ('F1', 0.026436236473461702), ('G1', 0.02642333956412242), ('D1', 0.026287556289978215), ('F3', 0.02627189703164849), ('G2', 0.02623548140362884), ('G3', 0.025226475403360565), ('R4', 0.02470269539588994), ('C3', 0.02461278154436033), ('C2', 0.024277277672009677), ('CC2', 0.024123546689698183), ('CC3', 0.02387930350591206), ('B2', 0.023679149510352198), ('H1', 0.023605611948805727), ('T1', 0.023568261902277017), ('B3', 0.023385974163561578), ('B1', 0.022932178923787804), ('T2', 0.0223499306260217), ('A2', 0.02207211359722249), ('A1', 0.02187796646490062), ('CC1', 0.01924645324586909), ('CH2', 0.010569914855578342), ('CH3', 0.009071178593534675), ('CH1', 0.00875718140944529)])
    if len(result) == 0: print("P ", end='')
    else:
        print(f"Fail with monopoly({numSides}, {numIterations}) for the following entries")
        print(result)
        correct = False

    numSides, numIterations = 23, 500
    result = equal(monopoly(numSides, numIterations), [('JAIL', 0.0595021468356409), ('GO', 0.034796530530114424), ('R1', 0.032622681807706944), ('H2', 0.030141408433562975), ('E3', 0.029918006775785187), ('C1', 0.02893218908326666), ('R3', 0.028399268637238316), ('U1', 0.027342106949448344), ('R2', 0.02727612417386418), ('U2', 0.02710500926583312), ('T1', 0.0263595402788935), ('D3', 0.026069311716704572), ('G3', 0.025916753059677482), ('R4', 0.025859970532042788), ('G2', 0.02577176525845487), ('H1', 0.025722070755163577), ('G1', 0.02571110904578055), ('F3', 0.025636407317300953), ('T2', 0.025576975172555503), ('F2', 0.025451204212515538), ('F1', 0.02535634716497447), ('A1', 0.025157885921381726), ('E2', 0.025103218772011115), ('A2', 0.0249616972432443), ('E1', 0.024781809151497698), ('FP', 0.024616923984917688), ('B1', 0.024567161456889936), ('B2', 0.02449582648748532), ('B3', 0.02442064400110464), ('D2', 0.024404041548016293), ('D1', 0.02425249886970578), ('C2', 0.024179958417883115), ('C3', 0.024163817540252718), ('CC3', 0.024022446706022573), ('CC1', 0.02192549008094382), ('CC2', 0.021257703320034467), ('CH3', 0.009672762645433026), ('CH2', 0.009353122325811406), ('CH1', 0.009196064520840569)])
    if len(result) == 0: print("P ", end='')
    else:
        print(f"Fail with monopoly({numSides}, {numIterations}) for the following entries")
        print(result)
        correct = False

    numSides, numIterations = 6, 1000
    result = equal(monopoly(numSides, numIterations), [('JAIL', 0.058964198687093815), ('E3', 0.03187794862075873), ('GO', 0.031138028172334374), ('D3', 0.030710242941460457), ('R3', 0.030636965006219947), ('R1', 0.02993126856493471), ('R2', 0.029186117197725316), ('D2', 0.029165169938974958), ('FP', 0.028748259330765538), ('E1', 0.028303543623739765), ('U2', 0.028107368145211385), ('D1', 0.027767510329905144), ('E2', 0.02738576557848951), ('C1', 0.027359908188830717), ('F1', 0.027065109440749927), ('G1', 0.02686591663261448), ('F2', 0.02679312586712327), ('H2', 0.02646925903077695), ('G2', 0.02633846361903784), ('U1', 0.02627460908675578), ('F3', 0.02591184851712412), ('CC2', 0.025718068109769208), ('G3', 0.02510469545831717), ('C3', 0.024673747662671615), ('R4', 0.024458957033056714), ('C2', 0.023855328143379304), ('CC3', 0.023765699659950613), ('T1', 0.023507772262957007), ('B2', 0.023470106510337593), ('B3', 0.023306471017037297), ('B1', 0.02285359459972436), ('H1', 0.02202178225623118), ('T2', 0.02193106960442769), ('A2', 0.021857914541241332), ('A1', 0.021524215848569166), ('CC1', 0.018997690635651363), ('CH2', 0.01047696536997358), ('CH1', 0.008760265657546134), ('CH3', 0.008715029108526385)])
    if len(result) == 0: print("P ", end='')
    else:
        print(f"Fail with monopoly({numSides}, {numIterations}) for the following entries")
        print(result)
        correct = False

    print()
    print()
    print("Speed test for monopoly()")    
    if not correct: print("fail (since the algorithm is not correct)")
    else:                
        numIterations, repeat = 300, 10
        tSpeedCompare = timeit.timeit(lambda: simpleGame(40, 12, numIterations, False), number=repeat)/repeat
        tSubmittedCode = timeit.timeit(lambda: monopoly(6, numIterations), number=repeat)/repeat    
        print(f"For numIterations = {numIterations}")
        print(f"Average running times of the submitted code {tSubmittedCode:.10f} and simpleGame {tSpeedCompare:.10f}")
        if tSubmittedCode < tSpeedCompare * 1.2: print("pass")
        else: print("fail")
        print()
        