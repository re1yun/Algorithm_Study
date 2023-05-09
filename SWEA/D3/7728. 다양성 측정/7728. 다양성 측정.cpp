#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        string X;  cin >> X;
        int arr[10] = {0, };
        int res = 0;
        for(char c : X)
            arr[c - '0'] = 1;
        for(int i = 0; i < 10; i++){
            if(arr[i] != 0)
                res++;
        }
        cout << "#" << test << " " << res << endl;
    }
    return 0;
}