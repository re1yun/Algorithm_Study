# 완주하지 못한 선수
## 문제 설명

수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.
## 제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.
## 입출력 예
participant	completion	return
["leo", "kiki", "eden"]	["eden", "kiki"]	"leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	["josipa", "filipa", "marina", "nikola"]	"vinko"
["mislav", "stanko", "mislav", "ana"]	["stanko", "ana", "mislav"]	"mislav"
## 입출력 예 설명
### 예제 #1
"leo"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.
### 예제 #2
"vinko"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.
### 예제 #3
"mislav"는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.
※ 공지 - 2023년 01월 25일 테스트케이스가 추가되었습니다.

***

처음에 간단하게 두 개의 for문 loop을 돌면서 지우는 방법을 시도했는데, 일반적인 상황에서는 괜찮지만 input이 커지면 시간초과가 발생하였다.
그 후에는 completion을 iterate 하면서 find()함수와 erase()함수를 사용했다. 그러나 상황이 똑같아서 뭔가 다른 방법이 필요할 것 같았다.
생각해보니 위 두 방식 모두 적어도 O(n^2)의 시간복잡도를 가지는 것 같아서, completion을 처음에 iterate하며 map에 저장해주고, participant 값이 map에 없으면 바로 끊어내는 방식도 괜찮을 것 같다. 근데 문제가 있다. 동명이인이 있다.

마지막으로 생각해낸 방법이 participant와 completion을 모두 sort해주고, 순서대로 비교해주다가 다른 점이 나오면 리턴해주는 방법을 사용하여 효율성 테스트도 통과했다.

***
문제 링크: [링크](https://school.programmers.co.kr/learn/courses/30/lessons/42576)