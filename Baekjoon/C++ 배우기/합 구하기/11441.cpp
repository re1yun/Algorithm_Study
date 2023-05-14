#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    int N, M;       cin >> N;
    int A[100001] = {0, };
    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        A[i] = A[i - 1] + num;
    }
    cin >> M;
    for(int k = 0; k < M; k++){
        int i, j;
        cin >> i >> j;
        cout << A[j] - A[i - 1] << "\n";
    }
    return 0;
}