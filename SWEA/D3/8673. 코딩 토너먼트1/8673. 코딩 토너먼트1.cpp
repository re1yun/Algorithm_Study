#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int K;  cin >> K;
        // init and first round
        int res = 0;
        queue<int> s;
        for(int i = 0; i < pow(2, K - 1); i++){
            int A, B;   cin >> A >> B;
            if(A == B)
                s.push(A);
            else if(A > B){
                s.push(A);
                res += A - B;
            }
            else{
                s.push(B);
                res += B - A;
            }
        }
        // proceed until last round
        while(!s.empty()){
            int tmp = s.front();
            s.pop();
            // if there is no opponent
            if(s.empty())
                break;
            int tmp2 = s.front();
            s.pop();
            if(tmp == tmp2)
                s.push(tmp);
            else if(tmp > tmp2){
                s.push(tmp);
                res += tmp - tmp2;
            }
            else{
                s.push(tmp2);
                res += tmp2 - tmp;
            }
        }
        cout << "#" << test << " " << res << endl;
    }
    return 0;
}