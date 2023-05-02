#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        string s;   cin >> s;
        long long a = 1, b = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                b += a;
            }
            else if(s[i] == 'R')
                a += b;
        }
        cout << "#" << test << " " << a << " " << b << endl;
    }
    return 0;
}