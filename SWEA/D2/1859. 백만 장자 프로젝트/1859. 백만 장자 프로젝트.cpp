#include <iostream>

using namespace std;

int num[1000002] = {0, };

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N;  cin >> N;
        long long result = 0;
        for(int i = 0; i < N; i++){
            cin >> num[i];
        }

        int max = num[N-1];
        for(int i = N-2; i >= 0; i--){
            if(num[i] < max){
                result += max - num[i];
            }
            else{
                max = num[i];
            }
        }
        cout << result << endl;
    }
    return 0;
}