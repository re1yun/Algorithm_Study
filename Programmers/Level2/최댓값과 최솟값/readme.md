# 최댓값과 최솟값
## 문제 설명

문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.
## 제한 조건
s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.
## 입출력 예
s	return
"1 2 3 4"	"1 4"
"-1 -2 -3 -4"	"-4 -1"
"-1 -1"	"-1 -1"

***

sstream 헤더 파일의 stringstream을 이용해서 공백을 기준으로 문자열을 나눠주었다. getline()과 함께쓰면 delimiter를 지정할 수 있어 좋은거 같다. 만약 delimiter를 여러개 설정하고 싶다면 getline을 || 를 쓰면 가능하다한다.

다른 방법은 find()와 substr()을 사용하는 방법이 있겠다.

***
문제 링크: [링크](https://school.programmers.co.kr/learn/courses/30/lessons/12939)