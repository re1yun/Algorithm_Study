#include <iostream>

using namespace std;

int cmp(int x, int y){
    if(x < y)
        return y;
    else
        return x;
}

int calc(int score[2][100002], int total){
    int calcul = 0;
    int check[2][total + 2] = {0,};

    check[0][0] = score[0][0];
    check[1][0] = score[1][0];
    check[0][1] = score[0][1] + check[1][0];
    check[1][1] = score[1][1] + check[0][0];

    for(int i = 2; i < total; i++){
        check[0][i] = score[0][i] + cmp(check[1][i - 1], check[1][i - 2]);
        check[1][i] = score[1][i] + cmp(check[0][i - 1], check[0][i - 2]);
    }

    return cmp(check[0][total - 1], check[1][total - 1]);
}

int main(){
    int T;      cin >> T;
    for(int i = 0; i < T; i++){
        int N;      cin >> N;
        int score[2][100002] = {0,};
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < N; k++){
                cin >> score[j][k];
            }
        }
        int result = calc(score, N);
        cout << result << "\n";
    }
    return 0;
}