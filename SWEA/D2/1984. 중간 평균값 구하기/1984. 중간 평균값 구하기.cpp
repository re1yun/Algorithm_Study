#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        vector<int> num;
        long long sum = 0;
        for(int i = 0; i < 10; i++){
            int temp;   cin >> temp;
            num.push_back(temp);
            sum += temp;
        }
        sort(num.begin(), num.end());
        cout << round((sum - num[0] - num[9]) / 8.0) << endl;
    }
    return 0;
}