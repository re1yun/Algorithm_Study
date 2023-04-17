***

첫 줄은 1부터 N까지 임을 알 수 있다.
마지막 줄은 2N + (N - 2)부터 2N + (N - 2) - N까지 임을 알 수 있다.
두번째 줄은 홀수의 경우 3N - 1, 짝수의 경우 3N 부터 시작하여 N - 1동안 증가시켜준다.

중간 줄을 생각해봐야한다.

1 2 3
8 9 4
7 6 5

1  2  3  4
12 13 14 5
11 16 15 6
10 9  8  7

1  2  3  4  5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

뭔가 패턴을 찾으면 안되고...막힐때까지 가다가 오른쪽으로 트는 방법으로 해야할까? 수가 커지면 너무 많아져서 패턴을 찾는 문제는 아닌 것 같다.
2차원 배열을 진행하면서 다음 진행 공간에 값이 있거나 공간이 없으면 트는 방법을 반복해주면 되겠다.

그렇다. 반복해주었다. 단순 구현 문제인듯 하다.

***
문제 링크: [링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&contestProbId=AV5PobmqAPoDFAUq&categoryId=AV5PobmqAPoDFAUq&categoryType=CODE&problemTitle=&orderBy=PASS_RATE&selectCodeLang=ALL&select-1=2&pageSize=10&pageIndex=2)
