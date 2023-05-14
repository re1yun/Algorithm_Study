#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int N, result = 0;      cin >> N;
    int A[1001] = {0,};
    int dp[1001] = {0,};
    for(int i = 0; i < N; i++){
        cin >> A[i];
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[i] > A[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        if(result < dp[i]){
            result = dp[i];
        }
    }
    cout << result;
    return 0;
}