# 소수 찾기
## 문제 설명

1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요.
소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.
(1은 소수가 아닙니다.)
## 제한 조건
n은 2이상 1000000이하의 자연수입니다.
## 입출력 예
n	result
10	4
5	3
## 입출력 예 설명
### 입출력 예 #1
1부터 10 사이의 소수는 [2,3,5,7] 4개가 존재하므로 4를 반환
### 입출력 예 #2
1부터 5 사이의 소수는 [2,3,5] 3개가 존재하므로 3를 반환

***

input으로 주어지는 n의 크기가 매우 크기 때문에 이걸 일일히 처음부터 찾는다면 시간이 많이 걸릴 듯하다. 
P(2) = 1
P(3) = 2
P(5) = 3
P(7) = 4
P(11) = 5
P(13) = 6
P(17) = 7
P(19) = 8
P(23) = 9

각 수를 소수로 나눠주는 방식을 써봤는데 효율성 테스트에서 실패했다.
그래서 각 소수의 배수를 지워주는 방식인 에라토스테네스의 체를 시도해보기로 했다.

성공했다.

***
문제 링크: [링크](https://school.programmers.co.kr/learn/courses/30/lessons/12921)