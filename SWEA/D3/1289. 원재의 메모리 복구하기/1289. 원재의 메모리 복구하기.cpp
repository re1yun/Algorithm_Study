#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        string s;   cin >> s;
        int ans = 0, idx =0;
        // find first 1 from the string
        while(s[idx] == '0')
            idx++;
        // start from next bit
        for(; idx < s.size(); idx++){
            // if fliped even times and if current digit is 1, then we need to flip
            if(s[idx] == '1' && ans % 2 == 0)
                ans++;
            else if(s[idx] == '0' && ans % 2 == 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}