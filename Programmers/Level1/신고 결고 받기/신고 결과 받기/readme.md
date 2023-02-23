# 신고 결고 받기
## 문제 설명
신입사원 무지는 게시판 불량 이용자를 신고하고 처리 결과를 메일로 발송하는 시스템을 개발하려 합니다. 무지가 개발하려는 시스템은 다음과 같습니다.
각 유저는 한 번에 한 명의 유저를 신고할 수 있습니다.
신고 횟수에 제한은 없습니다. 서로 다른 유저를 계속해서 신고할 수 있습니다.
한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.
k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.
다음은 전체 유저 목록이 ["muzi", "frodo", "apeach", "neo"]이고, k = 2(즉, 2번 이상 신고당하면 이용 정지)인 경우의 예시입니다.
유저 ID	유저가 신고한 ID	설명
"muzi"	"frodo"	"muzi"가 "frodo"를 신고했습니다.
"apeach"	"frodo"	"apeach"가 "frodo"를 신고했습니다.
"frodo"	"neo"	"frodo"가 "neo"를 신고했습니다.
"muzi"	"neo"	"muzi"가 "neo"를 신고했습니다.
"apeach"	"muzi"	"apeach"가 "muzi"를 신고했습니다.
각 유저별로 신고당한 횟수는 다음과 같습니다.
유저 ID	신고당한 횟수
"muzi"	1
"frodo"	2
"apeach"	0
"neo"	2
위 예시에서는 2번 이상 신고당한 "frodo"와 "neo"의 게시판 이용이 정지됩니다. 이때, 각 유저별로 신고한 아이디와 정지된 아이디를 정리하면 다음과 같습니다.
유저 ID	유저가 신고한 ID	정지된 ID
"muzi"	["frodo", "neo"]	["frodo", "neo"]
"frodo"	["neo"]	["neo"]
"apeach"	["muzi", "frodo"]	["frodo"]
"neo"	없음	없음
따라서 "muzi"는 처리 결과 메일을 2회, "frodo"와 "apeach"는 각각 처리 결과 메일을 1회 받게 됩니다.
이용자의 ID가 담긴 문자열 배열 id_list, 각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열 report, 정지 기준이 되는 신고 횟수 k가 매개변수로 주어질 때, 각 유저별로 처리 결과 메일을 받은 횟수를 배열에 담아 return 하도록 solution 함수를 완성해주세요.
## 제한사항
2 ≤ id_list의 길이 ≤ 1,000
1 ≤ id_list의 원소 길이 ≤ 10
id_list의 원소는 이용자의 id를 나타내는 문자열이며 알파벳 소문자로만 이루어져 있습니다.
id_list에는 같은 아이디가 중복해서 들어있지 않습니다.
1 ≤ report의 길이 ≤ 200,000
3 ≤ report의 원소 길이 ≤ 21
report의 원소는 "이용자id 신고한id"형태의 문자열입니다.
예를 들어 "muzi frodo"의 경우 "muzi"가 "frodo"를 신고했다는 의미입니다.
id는 알파벳 소문자로만 이루어져 있습니다.
이용자id와 신고한id는 공백(스페이스)하나로 구분되어 있습니다.
자기 자신을 신고하는 경우는 없습니다.
1 ≤ k ≤ 200, k는 자연수입니다.
return 하는 배열은 id_list에 담긴 id 순서대로 각 유저가 받은 결과 메일 수를 담으면 됩니다.
## 입출력 예
id_list	report	k	result
["muzi", "frodo", "apeach", "neo"]	["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]	2	[2,1,1,0]
["con", "ryan"]	["ryan con", "ryan con", "ryan con", "ryan con"]	3	[0,0]
## 입출력 예 설명
### 입출력 예 #1
문제의 예시와 같습니다.
### 입출력 예 #2
"ryan"이 "con"을 4번 신고했으나, 주어진 조건에 따라 한 유저가 같은 유저를 여러 번 신고한 경우는 신고 횟수 1회로 처리합니다. 따라서 "con"은 1회 신고당했습니다. 3번 이상 신고당한 이용자는 없으며, "con"과 "ryan"은 결과 메일을 받지 않습니다. 따라서 [0, 0]을 return 합니다.

***

문제 푸는데 막힌 부분은 없었는데 구현하는데 시간이 많이 걸렸다.
구현 과정을 줄이는 것이 중요할 것 같다.
생각 과정은 이러하다

유저마다 받는 메일을 쉽게 카운트할 수 있게 unordered_map 형식으로 id_list를 변환해주었다.
다음에는 report를 하나씩 돌면서 reporter와 reported를 구분해주었고, unordered_multimap 형식의 report_list를 만들어주었다.
여기서는 사실 3가지 방법을 생각했다.
1. reporter를 key로, reported를 value로 저장하여, 만약 value 중에 이미 신고한 유저가 있다면 그냥 넘어가기
2. reported를 key로, reporter를 value로 저장하여, 만약 value 중에 이미 신고를 당한 유저가 있다면 그냥 넘어가기
3. report에서 duplicate를 제거하고 바로 저장하기
3번째 방법이 쉬울 것 같았는데, 생각하다보니 내가 처음 unordered_map 형식으로 index_list를 만들어버린 바람에 2번째 방법으로 진행했다. 왜냐면 나중에 k보다 큰 애들만 answer에 저장을 해줘야했기 때문이다.
근데 지금 생각해보니, 3번째 방법으로 진행하되, 나중에 answer에 값을 저장할 때 k보다 작으면 그냥 0을 집어넣는 방법을 진행했으면 더 빨리 끝낼 수 있었을 것 같다. 아쉽다.

암튼, 다음에는 report_list를 돌면서 신고당한 reported의 수가 k보다 높을 경우, 각 value마다 unordered_map인 index_list에 값을 더해주었다.
그리고 마지막으로 in_list를 돌면서 해당되는 값을 answer에 저장해주고 반환하였다.

unordered_multimap을 처음 사용해보았고, iterate하는 과정을 처음해봐서 구현하는데 시간이 좀 걸린거 같다. 그 이외에도 문제 해결 방식이 좀 더 간편할 수 있었을거 같아 아쉽다.
다음에는 시간을 조금 더 써서 문제 해결 방식을 구현해보고 코딩을 시작해야겠다.

PS: 코드에 cout이나 print을 사용하여 출력결과가 너무 많아질 경우, 프로그래머스 코드 제출에서 답이 제대로 제출됨에도 불구하고 에러가 뜬다!

***
문제 링크: [링크](https://school.programmers.co.kr/learn/courses/30/lessons/92334)
