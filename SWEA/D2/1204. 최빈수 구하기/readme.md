***

처음에 map을 사용해서 빈도수를 세어주었는데, 문제는 빈도수를 다 세고 난 후 sort의 문제였다.
알고보니 algorithm의 sort()함수는 map을 바로 정렬하지 못했다. 이유는 map의 경우 tree 형태로 형성되기 때문에 sort의 개념이 통하지 않았던 것 같다. 아마도 이는 set에도 동일하게 적용될 듯 하다. 따라서 임시방편으로 vector로 변환하여 sort를 진행해주었는데 속도가 느린 것이 체감되었다.

***
문제 링크: [링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&contestProbId=AV13zo1KAAACFAYh&categoryId=AV13zo1KAAACFAYh&categoryType=CODE&problemTitle=&orderBy=PASS_RATE&selectCodeLang=ALL&select-1=2&pageSize=10&pageIndex=3)
