#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N;  cin >> N;
        vector<int> n;
        for(int i = 0; i < N; i++){
            int temp = 0;   cin >> temp;
            n.push_back(temp);
        }
        sort(n.begin(), n.end());
        for(int i = 0; i < N; i++){
            cout << n[i] << " ";
        }
        cout << endl;
    }
    return 0;
}