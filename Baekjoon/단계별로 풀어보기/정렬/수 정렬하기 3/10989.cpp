#include <iostream>

#define MAX_NUM 10000
using namespace std;

int main(){
    int N = 0, a;     cin >> N;
    int count[MAX_NUM + 1] = {0,};
    for(int i = 0; i < N; i++){
        cin >> a;
        count[a]++;
    }
    for(int i = 1; i <= MAX_NUM; i++) {
        for(int j = 0; j < count[i]; j++){
            cout << i << "\n";
        }
    }
    return 0;
}