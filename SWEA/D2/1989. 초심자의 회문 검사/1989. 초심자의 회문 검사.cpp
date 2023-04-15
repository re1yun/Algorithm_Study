#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        string s;   cin >> s;
        // revS: reverse s
        string revS = s;
        reverse(revS.begin(), revS.end());
        int ans = 1;
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != revS[i]){
                ans = 0;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}