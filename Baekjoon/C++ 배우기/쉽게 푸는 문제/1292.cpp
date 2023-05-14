#include <iostream>

using namespace std;

int main(){
    int list[1001] = {0,};
    int cnt = 0;
    for(int i = 1; i < 1001; i++){
        for(int j = 0; j < i && cnt < 1000; j++){
            list[cnt++] = i;
        }
    }
    int a, b;       cin >> a >> b;
    int ans = 0;
    for(int i = a - 1; i < b; i++){
        ans += list[i];
    }
    cout << ans;
    return 0;
}