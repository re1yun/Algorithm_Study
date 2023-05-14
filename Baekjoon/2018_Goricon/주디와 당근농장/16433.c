#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N = 0, R, C, cnt = 0;
    scanf("%d %d %d", &N, &R, &C);
    /*char **farm = (char **)malloc(sizeof(char) * (N + 1));
    for (int i = 0; i < N + 1; i++){
        farm[i] = (char *)malloc(sizeof(char) * (N + 1));
    }*/
    char farm[100][100];
    if(((R % 2) == 0 && (C % 2) == 1) || ((R % 2) == 1 && (C % 2) == 0)){
        cnt = 1;
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cnt == 0){
                //strcpy(farm[i][j], "v");
                farm[i][j] = 'v';
                cnt = 1;
            }else{
                //strcpy(farm[i][j], ".");
                farm[i][j] = '.';
                cnt = 0;
            }
        }
        if((cnt == 1 && N % 2 == 0) || (cnt == 0 && N % 2 != 0)){
            cnt = 0;
        }
        else{
            cnt = 1;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%c", farm[i][j]);
        }
        printf("\n");
    }
    return 0;
}