#include <iostream>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N;  cin >> N;
        int max = 0, min = 0, prev = 0;
        for(int i = 0; i < N; i++){
            int num;    cin >> num;
            if(i == 0)
                prev = num;
            else{
                if(prev < num && num - prev > max)
                    max = num - prev;
                else if(prev > num && prev - num > min)
                    min = prev - num;
                prev = num;
            }
        }
        cout << max << " " << min << endl;
    }
    return 0;
}