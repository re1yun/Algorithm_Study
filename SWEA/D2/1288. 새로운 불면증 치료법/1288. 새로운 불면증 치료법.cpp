#include <iostream>
#include <string>

using namespace std;

bool checkAll(bool check[10]){
    for(int i = 0; i < 10; i++){
        if(check[i] == false) return false;
    }
    return true;
}

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int n, N, cnt = 2;  cin >> n;
        N = n;
        bool check[10] = {false, };
        while(checkAll(check) == false){
            string s = to_string(N);
            for(int i = 0; i < s.size(); i++){
                check[s[i] - '0'] = true;
            }
            N = n * cnt++;
        }
        cout << n * (cnt - 2) << endl;
    }
    return 0;
}