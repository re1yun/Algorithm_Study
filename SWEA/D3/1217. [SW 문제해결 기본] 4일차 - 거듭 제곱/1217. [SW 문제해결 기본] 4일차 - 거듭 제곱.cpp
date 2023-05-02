#include <iostream>

using namespace std;

int factorial(int res, int N, int M){
    if(M == 0)
        return res;
    else
	    return factorial(res * N, N, M - 1);
}

int main(){
    int T = 10;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int tcase;	cin >> tcase;
        int N, M;   cin >> N >> M;
        int res = 1;
        res = factorial(res, N, M);
        cout << res << endl;
    }
    return 0;
}