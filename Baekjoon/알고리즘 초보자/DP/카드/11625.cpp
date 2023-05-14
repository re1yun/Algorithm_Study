#include <iostream>
#include <math.h>

using namespace std;

int main(){
    cin.tie(NULL);
    int N;      cin >> N;
    int dp[100001] = {0,};
    int count[100001] = {0,};
    for(int i = 0; i < N; i++){
        int num, j;     cin >> num;
        for(j = 0; j < i; j++){
            if(dp[j] == num){
                count[j]++;
                break;
            }
        }
        if(i == j){
            dp[i] = num;
            count[i]++;
        }
    }
    int cnt = 0, maxcnt = 9999999, minval = pow(2, 64);
    while(dp[cnt] != 0){
        if(maxcnt >= count[cnt] && minval > dp[cnt]){
            maxcnt = count[cnt];
            minval = dp[cnt];
        }
        cnt++;
    }
    cout << minval;
    return 0;
}