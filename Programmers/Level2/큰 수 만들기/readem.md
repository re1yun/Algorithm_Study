# 큰 수 만들기
## 문제 설명

어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.
예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.
문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다. number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.
## 제한 조건
number는 2자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다.
## 입출력 예
number	k	return
"1924"	2	"94"
"1231234"	3	"3234"
"4177252841"	4	"775841"

***

처음부터 수를 돌며 뒤에 존재하는 수보다 더 작은 수는 제외해주며 돌아주면 가장 큰 수를 구할 수 있다.

위 방법을 시도해보았는데, 각종 반례 및 테스트 케이스를 통과하였으나 이상하게 본래 테스트는 대부분 통과하지 못하였다. 따라서 위 알고리즘에 문제가 있다 판단하고, 지워야하는 수만큼 범위를 정해 이 범위를 돌면서 가장 큰 수를 찾고, 그 수부터 뒤 숫자들을 탐색하며 가장 큰 수를 찾아 더해주는 방식으로 진행했다.

***
문제 링크: [링크](https://school.programmers.co.kr/learn/courses/30/lessons/42883#)
