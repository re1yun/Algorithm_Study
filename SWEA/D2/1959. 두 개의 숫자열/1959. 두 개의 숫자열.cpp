#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N, M;   cin >> N >> M;
        vector<int> A(N), B(M);
        for(int i = 0; i < N; i++)  cin >> A[i];
        for(int i = 0; i < M; i++)  cin >> B[i];
        int ans = 0;
        if(N > M){
            for(int i = 0; i < N - M + 1; i++){
                int sum = 0;
                for(int j = 0; j < M; j++){
                    sum += A[i + j] * B[j];
                }
                ans = max(ans, sum);
            }
        }
        else{
            for(int i = 0; i < M - N + 1; i++){
                int sum = 0;
                for(int j = 0; j < N; j++){
                    sum += B[i + j] * A[j];
                }
                ans = max(ans, sum);
            }
        }
        cout << ans << endl;
    }
    return 0;
}