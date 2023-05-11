#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        int N, M;   cin >> N >> M;
        unordered_map<int, int> m;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(m.find(i + j) == m.end())
                    m[i + j] = 1;
                else
                    m[i + j]++;
            }
        }
        // convert into vector in order to sort
        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
            if(a.second == b.second)
                return a.first < b.first;
            else
                return a.second > b.second;
        });
        cout << "#" << test << " ";
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == v[0].second)
                cout << v[i].first << " ";
            else
                break;
        }
        cout << endl;
    }
    return 0;
}