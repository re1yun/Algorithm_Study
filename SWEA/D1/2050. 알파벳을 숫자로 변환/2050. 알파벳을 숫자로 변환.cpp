#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        cout << s[i] - 'A' + 1 << " ";
    }
    return 0;
}