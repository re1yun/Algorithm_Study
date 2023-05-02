***

한참을 헤매다가 결국 문제를 풀 수 있었다. 분명 간단한 문제로 주어지는 string을 따라서 a와 b만 수정해주면 되는 문제였는데 왜인지 계속해서 정답은 나오는데 시간제한에 걸렸다. 그래서 혹시나 하는 마음에 dp로 풀었는데도 계속해서 시간 제한이 걸렸다. 결국 다른 사람의 코드도 열어서 확인했는데 내 첫 코드와 별반 다르지 않았다. 통과하는 코드를 하나하나 비교해가며 실험해본 결과, 내가 유일하게 달랐던 부분은 cout을 처음에 출력하고 나중에 결과값을 계산한 다음에 다시 cout을 실행해주었는데, 그게 문제였다. 너무 답답했는데 충격적이었다. cout의 경우 실행시간이 좀 걸린다는 것을 배웠다. 앞으로 cout의 사용을 최소화해야겠다.

***
문제 링크: [링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AXgZSOn6ApIDFASW&categoryId=AXgZSOn6ApIDFASW&categoryType=CODE&problemTitle=&orderBy=PASS_RATE&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=1)
