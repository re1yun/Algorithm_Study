#include <iostream>

using namespace std;

int main(){
    int T;      cin >> T;
    for(int t = 0; t < T; t++){
        int n;      cin >> n;
        int min = 100, max = 0;
        for(int i = 0; i < n; i++){
            int num;    cin >> num;
            if(num < min){
                min = num;
            }
            if(num > max){
                max = num;
            }
        }
        cout << (max - min) * 2 << "\n";
    }
    return 0;
}