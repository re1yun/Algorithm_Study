#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        string s;   cin >> s;
        string temp1 = "", temp2 = "";
        for(int i = 0; i < 10; i++){
            temp1 += s[i];
            temp2 = s.substr(temp1.size(), temp1.size());
            if(temp1 == temp2)
                break;
        }
        cout << temp1.size() << endl;
    }
    return 0;
}