#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        string s;   cin >> s;
        string ans = "";
        for(char c : s){
            if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'){
                ans += c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}