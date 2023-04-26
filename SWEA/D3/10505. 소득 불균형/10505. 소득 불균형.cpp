#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N;  cin >> N;
        int sum = 0;
        int ppl[N];
        for(int i = 0; i < N; i++){
            cin >> ppl[i];
            sum += ppl[i];
        }
        int avg = sum / N;
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(ppl[i] <= avg)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}