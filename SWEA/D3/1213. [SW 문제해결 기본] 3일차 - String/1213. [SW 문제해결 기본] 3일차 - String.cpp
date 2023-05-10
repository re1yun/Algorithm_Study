#include <iostream>
#include <string>

using namespace std;

int main(){
    int T = 10;
    for(int test = 1; test <= T; test++){
        int tc; cin >> tc;
        string word, str;   cin >> word >> str;
        int cnt = 0;
        auto pos = str.find(word, 0);
        if(pos != string::npos){
            cnt++;
            while(pos != string::npos){
                pos = str.find(word, pos + 1);
                if(pos != string::npos)
                    cnt++;
            }
        }
        cout << "#" << test << " " << cnt << endl;
    }
    return 0;
}