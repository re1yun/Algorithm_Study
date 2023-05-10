#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int N, K;   cin >> N >> K;
        int arr[101] = {0, };
        for(int i = 0; i < K; i++){
            int temp;   cin >> temp;
            arr[temp] = 1;
        }
        cout << "#" << test << " ";
        for(int i = 1; i <= N; i++){
            if(arr[i] == 0)
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}