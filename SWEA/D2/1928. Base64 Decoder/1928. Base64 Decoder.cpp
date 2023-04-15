#include <iostream>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;
    // init dictionary
    map<char, int> dict;
    for(int i = 0; i < 26; i++){
        dict['A' + i] = i;
    }
    for(int i = 0; i < 26; i++){
        dict['a' + i] = i + 26;
    }
    for(int i = 0; i < 10; i++){
        dict['0' + i] = i + 52;
    }
    dict['+'] = 62;
    dict['/'] = 63;

    // algorithm
    // encoding: 3 bytes -> 4 bytes
    // this is to decode. 4 bytes -> 3 bytes
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        string s;   cin >> s;
        int len = s.length();
        for(int i = 0; i < len; i += 4){
            int num = 0;
            // take 4 bytes of string
            for(int j = 0; j < 4; j++){
                // num * 64: shift 6 bits to left
                num = num * 64 + dict[s[i + j]];
            }
            // take 3 bytes of num
            for(int j = 2; j >= 0; j--){
                // shift 8 bits to right
                cout << (char)((num >> (j * 8)) & 0xff);
            }
        }
        cout << endl;
    }
    return 0;
}