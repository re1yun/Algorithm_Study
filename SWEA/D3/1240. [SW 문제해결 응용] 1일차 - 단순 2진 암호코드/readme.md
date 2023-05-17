***

문제를 이해하는데 시간이 좀 걸렸다. 그렇지만 일단 이해하는 바로는 다음과 같다.
input의 첫 줄에는 두 정수가 주어지는데, 첫 정수는 앞으로 주어질 문자열의 개수를 나타내고, 다음 정수는 각 문자열의 길이를 나타낸다. 그 다음에 나오는 0부터 9까지의 직사각형은 문자열이 가리키는 정수를 나타낸다. 다만 이 문제에서는 모든 정수의 암호문 마지막은 1을 보유하고 있어서 마지막에 나오는 1부터 진행하는 것이 좋겠다. 따라서 문자열을 읽으며 1이 있는지 확인하고, 있으면 문자열을 reverse하여 각 암호문에 맞는 수를 홀수와 짝수 자리수로 나누어 저장해주면 된다.

***
문제 링크: [링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AV15FZuqAL4CFAYD&categoryId=AV15FZuqAL4CFAYD&categoryType=CODE&problemTitle=&orderBy=PASS_RATE&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=4)
