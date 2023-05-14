#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int N, result = 0;      cin >> N;
    int A[1001] = {0,};
    int dp1[1001] = {0,};
    int dp2[1001] = {0,};
    for(int i = 0; i < N; i++){
        cin >> A[i];
        dp1[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[i] > A[j] && dp1[i] < dp1[j] + 1){
                dp1[i] = dp1[j] + 1;
            }
        }
    }
    for(int i = N - 1; i >= 0; i--){
        dp2[i] = 1;
        for(int j = N; j > i; j--){
            if(A[i] > A[j] && dp2[j] + 1 > dp2[i]){
                dp2[i] = dp2[j] + 1;
            }
        }

    }
    for(int i = 0; i < N; i++){
        if(result < dp1[i] + dp2[i] - 1){
            result = dp1[i] + dp2[i] - 1;
        }
    }
    cout << result;
    return 0;
}