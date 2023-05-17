#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int T;  cin >> T;
    map<string, int> m = {
        {"1123", 0}, {"1222", 1}, {"2212", 2}, {"1141", 3}, {"2311", 4}, {"1321", 5}, {"4111",6}, {"2131", 7}, {"3121", 8}, {"2113",9}
    };
    for(int test = 1; test <= T; test++){
        int N, M;	cin >> N >> M;
        int even = 0, odd = 0, answer = 0;
        bool check = false;
        for(int i = 0; i < N; i++){
            if(check == false){
                string temp;	cin >> temp;
                // if no '1' exist, then skip
                if(temp.find('1') == string::npos)
                    continue;
                // reverse string to find index of first '1', or just iterate from back
                reverse(temp.begin(), temp.end());
                int index = 0;
                while(temp[index] != '1')
                    index++;
                for(int code = 0; code < 8; code++){
                    string codeStr = "";
                    int cnt = 1;
                    for(int count = index + 6; index < count; index++){
                        // compare with next number and if it is same, increase cnt
                        if(temp[index] == temp[index + 1])
                            cnt++;
                        // if not, add current cnt to codeStr and reset cnt
                        else{
                            codeStr += to_string(cnt);
                            cnt = 1;
                        }
                    }
                    index++;
                    // process last number
                    codeStr += to_string(cnt);
                
                    // if it is even position
                    if(code % 2 == 0)
                        even += m[codeStr];
                    else
                        odd += m[codeStr];
                }
                check = true;
            }
            else{
                string temp;	cin >> temp;
            }
        }
        if((even + odd * 3) % 10 == 0)
            answer = even + odd;
        else
            answer = 0;
        cout << "#" << test << " " << answer << endl;
    }
    return 0;
}
