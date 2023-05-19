#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int T;  cin >> T;
    map<char, char> m = {{'b', 'd'}, {'d', 'b'}, {'p', 'q'}, {'q', 'p'}};
    for(int test = 1; test <= T; test++){
        string temp;	cin >> temp;
        string answer = "";
        for(char c: temp){
            answer += m[c];
        }
        reverse(answer.begin(), answer.end());
        cout << "#" << test << " " << answer << endl;
    }
    return 0;
}