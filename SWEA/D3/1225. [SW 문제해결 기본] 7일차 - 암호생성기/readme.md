***

8개의 수를 입력받기 때문에 한바퀴를 정의할 수 있을 것 같다.
a b c d e f g h
1 2 3 4 5 1 2 3
4 5 1 2 3 4 5 1
2 3 4 5 1 2 3 4
5 1 2 3 4 5 1 2
3 4 5 1 2 3 4 5
즉 총 8번의 사이클을 돌면 큰 사이클 하나를 다시 도는 셈이 된다.
모든 수가 15보다 크다면 각 수의 15 나머지 값을 가지고 큰사이클을 돌면 시간을 단축할 수 있을 것이다.

단, 그냥 나머지 값을 쓰면 각각의 수의 15 곱 값이 다르기 때문에 오류가 난다. 따라서 가장 작은 수의 15 곱셈을 구하여 동일한 값을 각 숫자에게서 빼주는 것이 중요하다. 

***
문제 링크: [링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV14uWl6AF0CFAYD&categoryId=AV14uWl6AF0CFAYD&categoryType=CODE&problemTitle=&orderBy=PASS_RATE&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=2)
