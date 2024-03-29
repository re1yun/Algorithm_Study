/*
내 첫 생각....N과 K를 받는데, K는 N과 같거나 작다 ㅇㅇ
K만큼 포문을 돌면서 덧셈을 통해 N이 되는 가짓수를 찾아야하는 것 같다.
아니면 dp[201][201]이렇게 해서 해야한다. 얼마나 포문을 돌아야하는지 알 수 없다.
일단 포문을 돌 때, 마지막 포문부터 돌면서 N보다 크면...? 이거 아닌거 같다. 너무 많이 돈다. 매우 멍청함.
점화식이 있을텐데...?
dp[1][1] = 1
dp[2][1] = 1, dp[2][2] = 3. 02 20 11
dp[3][1] = 1. 3
dp[3][2] = 4. 03 30 12 21
dp[3][3] = 10. 003 012 021 030 300 102 201 120 210 111
뭔가 패턴이 있는거 같다. 
하나의 자리 수 3P1로 3을 만드는 가지수는 1개. 근데 자리수가 K이기 때문에 K개 3 / 3 에서 3개가 있을 수 있다
두개의 자리 수 3P2로 3을 만드는 가지수는 4개. 그래서 6개. permutation
그리고 N개의 자리 수로 N을 만드는 법은 단 하나 1만 더하는거.
dp[4][2] = . 04 40 13 31 22 뭔가 더하기 1? dp[6][2] = 7? 0 1 2 3 4 5 6 그러네 K가 2일때는 N + 1 
dp[i][1] = 1
dp[i][2] = i + 1
dp[i][3] = 순열로 더해주기? nPr인데 r-1 r-2 

permutation은 다음과 같이 구한다.
nPr 일 경우 n부터 r까지 내려가며 곱해준다. 즉 n * n - 1 * n - 2 * .... n - r까지

dp[6][4] = 6P1 + 6P2 + 6P3 + 1 답이 안나옴... ㅠ
dp[6][1] = 1
dp[6][2] = 7
dp[6][3] = 내 생각엔 6P1 + 6P2 + 1 = 6 + 120 + 1
3개의 수를 더해서 6을 만드는 거임...아 뭔가 잘못한듯 ㅠㅠ 
0은 뒤 두자리의 합이 6이 되어야함. 즉 7개.
1은 뒤 두자리의 합이 5가 되어야함. 즉 dp[5][2] 고로 6개
2은 뒤 두자리의 합이 4가 되어야함. 즉 dp[4][2]
3은 뒤 두자리으 합이 3이 되어야함. dp[3][2]
고로 dp[6][3]은 dp[6][2] + dp[5][2] + ....이거네

엥 그럼 dp[4][3]은 dp[4][2] + dp[3][2] + dp[2][2] = 5 + 4 + 3 = 12
재귀가 메모리랑 시간이 될라나...?
*/

#include <iostream>

using namespace std;


int main(){
    int N, K;       cin >> N >> K;
    long long dp[201][201] = {0,};
    for(int i = 0; i <= N; i++){
        dp[i][1] = 1;
    }
    for(int n = 0; n <= N; n++){
        for(int k = 2; k <= K; k++){
            for(int i = 0; i <= n; i++){
                dp[n][k] = dp[n][k] + dp[i][k - 1];
            }
            dp[n][k] %= 1000000000; 
        }
    }
    cout << dp[N][K];
    return 0;
}