#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[n / 2] << endl;
    return 0;
}