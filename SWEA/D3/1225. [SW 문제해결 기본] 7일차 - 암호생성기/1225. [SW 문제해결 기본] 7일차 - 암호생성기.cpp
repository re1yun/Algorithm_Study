#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T = 10;
    for(int test = 1; test <= T; test++){
        int tc; cin >> tc;
        queue<int> q;
        vector<int> v;
        for(int i = 0; i < 8; i++){
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        auto min = *min_element(v.begin(), v.end());
        int cnt = min / 15 - 1;
        for(int i = 0; i < 8; i++){
            q.push(v[i] - cnt * 15);
        }
        while(q.back() != 0){
            for(int i = 1; i <= 5; i++){
                int temp = q.front();
                q.pop();
                if(temp - i <= 0){
                    q.push(0);
                    break;
                }
                q.push(temp - i);
            }
        }
        cout << "#" << test << " ";
        for(int i = 0; i < 8; i++){
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }
    return 0;
}