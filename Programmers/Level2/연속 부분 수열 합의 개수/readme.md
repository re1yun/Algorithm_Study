# 연속 부분 수열 합의 개수
## 문제 설명

철호는 수열을 가지고 놀기 좋아합니다. 어느 날 철호는 어떤 자연수로 이루어진 원형 수열의 연속하는 부분 수열의 합으로 만들 수 있는 수가 모두 몇 가지인지 알아보고 싶어졌습니다. 원형 수열이란 일반적인 수열에서 처음과 끝이 연결된 형태의 수열을 말합니다. 예를 들어 수열 [7, 9, 1, 1, 4] 로 원형 수열을 만들면 다음과 같습니다.
그림.png
원형 수열은 처음과 끝이 연결되어 끊기는 부분이 없기 때문에 연속하는 부분 수열도 일반적인 수열보다 많아집니다.
원형 수열의 모든 원소 elements가 순서대로 주어질 때, 원형 수열의 연속 부분 수열 합으로 만들 수 있는 수의 개수를 return 하도록 solution 함수를 완성해주세요.
## 제한사항
3 ≤ elements의 길이 ≤ 1,000
1 ≤ elements의 원소 ≤ 1,000
## 입출력 예
elements	result
[7,9,1,1,4]	18
## 입출력 예 설명
### 입출력 예 #1
길이가 1인 연속 부분 수열로부터 [1, 4, 7, 9] 네 가지의 합이 나올 수 있습니다.
길이가 2인 연속 부분 수열로부터 [2, 5, 10, 11, 16] 다섯 가지의 합이 나올 수 있습니다.
길이가 3인 연속 부분 수열로부터 [6, 11, 12, 17, 20] 다섯 가지의 합이 나올 수 있습니다.
길이가 4인 연속 부분 수열로부터 [13, 15, 18, 21] 네 가지의 합이 나올 수 있습니다.
길이가 5인 연속 부분 수열로부터 [22] 한 가지의 합이 나올 수 있습니다.
이들 중 중복되는 값을 제외하면 다음과 같은 18가지의 수들을 얻습니다.
[1, 2, 4, 5, 6, 7, 9, 10, 11, 12, 13, 15, 16, 17, 18, 20, 21, 22]

***

[1]: 1
[1, 2]: 1, 2 // 3
[1, 2, 3]: 1, 2, 3 // 3, 4, 5 // 6
[1, 2, 3, 4]: 1, 2, 3, 4 // 3, 5, 7, 5 // 6, 9, 8, 7 // 10
[7, 9, 1, 1, 4]: 7, 9, 1, 1, 4 // 16, 10, 2, 5, 11 // 17, 11, 6, 12, 20 // 18, 15, 13, 21, 21 // 22

모든 수열의 개수마다 총 원소의 개수만큼 합이 일단 나온다. 즉 전체 합의 개수: n * (n - 1) + 1
관건은 중복된 원소의 개수를 빼주는 것이다. 

총 원소의 개수만큼 합이 항상 존재하기 때문에, 일일히 돌필요 없이, 한 줄을 하나씩 shift해서 더해주고 중복을 검색해주면 될 것 같다.

중복 검색에서 문제가 생겼었다. 시간이 초과했는데 일일히 find()함수를 적용해서 문제가 생겼다. set을 이용해주니 시간이 많이 단축되었다.
***
문제 링크: [링크](https://school.programmers.co.kr/learn/courses/30/lessons/131701)
