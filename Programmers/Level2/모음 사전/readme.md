# 모음 사전
## 문제 설명

사전에 알파벳 모음 'A', 'E', 'I', 'O', 'U'만을 사용하여 만들 수 있는, 길이 5 이하의 모든 단어가 수록되어 있습니다. 사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA"이며, 마지막 단어는 "UUUUU"입니다.
단어 하나 word가 매개변수로 주어질 때, 이 단어가 사전에서 몇 번째 단어인지 return 하도록 solution 함수를 완성해주세요.
## 제한사항
word의 길이는 1 이상 5 이하입니다.
word는 알파벳 대문자 'A', 'E', 'I', 'O', 'U'로만 이루어져 있습니다.
## 입출력 예
word	result
"AAAAE"	6
"AAAE"	10
"I"	1563
"EIO"	1189
## 입출력 예 설명
### 입출력 예 #1
사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA", "AAA", "AAAA", "AAAAA", "AAAAE", ... 와 같습니다. "AAAAE"는 사전에서 6번째 단어입니다.
### 입출력 예 #2
"AAAE"는 "A", "AA", "AAA", "AAAA", "AAAAA", "AAAAE", "AAAAI", "AAAAO", "AAAAU"의 다음인 10번째 단어입니다.
### 입출력 예 #3
"I"는 1563번째 단어입니다.
### 입출력 예 #4
"EIO"는 1189번째 단어입니다.

***

A -> 1번째 단어
E -> 아마도 1563 - 1 / 2, 즉 781번째 단어일 것이다
I -> 1563번째 단어
O
U

A, AA, AAA, AAAA, AAAAA, AAAAE, AAAAI, AAAAO, AAAAU, AAAE, AAAEA
AAAEE AAAEI AAAEO AAAEU AAAI

aaaa 4
aaae 10
aaai 16
aaao 22
aaau 28

aaa 3
aae 3 + 25 + 5 + 1 -> 34
aai 34 + 25 + 5 + 1 -> 67
aao 67 + 31 -> 98
aau 98 + 31 -> 129

aa 2
ae 129 + 31 -> 160 -> 2 + 125 + 37 + 1
ai 160 + 158 -> 318
ao 318 + 158 -> 576
au 576 + 158 -> 734

aua 735
aue 767
aui 798
auo
auu

auuuu 780
e 781
ea
eaa
eaaa
eaaaa

각 알파벳의 인덱스와 각 자리의 곱 값을 구해서, 각 자리수마다 끝까지 곱 값을 곱해 더해주면 답이 나온다.

***
문제 링크: [링크](https://school.programmers.co.kr/learn/courses/30/lessons/84512)
