#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run(int N, int K){
    int total = N - 1;
    int stop = 0;
    int cnt = 1;
    while(total >= 0){
        total -= K * cnt++;
    }
    cnt -= 1;
    if(cnt % 2 == 0){
        stop = -(K * (cnt / 2)) - total;
        printf("%d L\n", stop);
    }
    else{
        stop = K * (cnt / 2 + 1) + total;
        printf("%d R\n", stop);
    }
}

int main(){
    int T;  scanf("%d", &T);
    int N, K;
    /*int N[100001];
    int K[100001];
    for(int i = 0; i < T; i++){
        scanf("%d %d", &N[i], &K[i]);
    }*/
    for(int i = 0; i < T; i++){
        scanf("%d %d", &N, &K);
        run(N, K);
    }
    

    return 0;
}