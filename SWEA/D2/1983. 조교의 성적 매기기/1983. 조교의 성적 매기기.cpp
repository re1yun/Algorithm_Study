#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int N, K;   cin >> N >> K;
        int score[N];
        for(int i = 0; i < N; i++){
            int mid, fin, hw;   cin >> mid >> fin >> hw;
            score[i] = mid * 35 + fin * 45 + hw * 20;
        }
        int target = score[K-1];
        sort(score, score + N, greater<int>());
        int rank = 0;
        for(int i = 0; i < N; i++){
            if(score[i] == target){
                rank = i;
                break;
            }
        }
        if(rank < N / 10)   cout << "A+" << endl;
        else if(rank < N / 10 * 2)  cout << "A0" << endl;
        else if(rank < N / 10 * 3)  cout << "A-" << endl;
        else if(rank < N / 10 * 4)  cout << "B+" << endl;
        else if(rank < N / 10 * 5)  cout << "B0" << endl;
        else if(rank < N / 10 * 6)  cout << "B-" << endl;
        else if(rank < N / 10 * 7)  cout << "C+" << endl;
        else if(rank < N / 10 * 8)  cout << "C0" << endl;
        else if(rank < N / 10 * 9)  cout << "C-" << endl;
        else    cout << "D0" << endl;
    }
    return 0;
}