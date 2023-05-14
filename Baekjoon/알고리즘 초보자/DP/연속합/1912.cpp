#include <iostream>

using namespace std;

int main(){
    int N = 0;      cin >> N;
    int A[100001] = {0,};
    int dp[100001] = {0,};
    for(int i = 0; i < N; i++){
        cin >> A[i];
        dp[i] = A[i];
    }
    int sum = dp[0];
    for(int i = 1; i < N; i++){
        if(A[i] < dp[i - 1] + A[i]){
            dp[i] = dp[i - 1] + A[i];
        }
        if(sum < dp[i]){
            sum = dp[i];
        }
    }
    cout << sum;
    return 0;
}