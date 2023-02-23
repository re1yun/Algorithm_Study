# 자연수 뒤집어 배열로 만들기
## 문제 설명

자연수 n을 뒤집어 각 자리 숫자를 원소로 가지는 배열 형태로 리턴해주세요. 예를들어 n이 12345이면 [5,4,3,2,1]을 리턴합니다.
## 제한 조건
n은 10,000,000,000이하인 자연수입니다.
## 입출력 예
n	return
12345	[5,4,3,2,1]

***

long long으로 들어오는 input이었기 때문에 string으로 타입 변환 후 foreach문으로 answer에 순서대로 넣어주고,
<algorithm>의 reverse() 함수를 사용해 순서를 바꾸어 주었다.

***
문제 링크: [링크](https://school.programmers.co.kr/learn/courses/30/lessons/12932)