#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int date[1001] = { 0, };
int ddeuk[1001][1001];

int check(int tiger_choice, int c_date){    //tiger_choice는 어제 먹은 떡의 종류, c_date는 오늘이 몇번째 날인가?
    int flag = 0;
    for(int i = 1; i <= date[c_date]; i++){  //date[c_date]오늘 가진 떡의 개수
        if(tiger_choice == ddeuk[c_date][i]){   //호랑이가 어제 먹은 떡과 같을 경우 flag = 1
            flag = 1;
        }
        else{                                   //호랑이가 어제 먹은 떡과 다른 종류가 있을 경우 flag = 0
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    int N = 0;  scanf("%d%*c", &N);
    int flag = 0;
    for(int i = 0; i < N; i++){
        char message[500];
        gets(message);
        date[i] = atoi(message);
        for(int j = 0; j <= date[i]; j++){
            if(j == 0){
                ddeuk[i][j] = atoi(strtok(message, " "));
            }
            else{
                ddeuk[i][j] = atoi(strtok(NULL, " "));
            }
        }
    }
    int tiger_choice[10] = {0, };
    int temp = 0;
    for(int i = 0; i < N; i++){
        flag = 0;
        
        for(int j = 1; j <= date[i]; j++){
            temp = ddeuk[i][j];                 //temp에 떡의 종류를 저장
            if(i != 0 && temp == tiger_choice[i - 1]){    //전날 고른 떡과 같다면 스킵
                continue;
            }
            if(check(temp, i + 1) == 0){        //check가 0이면 다른 떡을 선택할 수 있다는 뜻
                tiger_choice[i] = ddeuk[i][j];
                flag = 1;
                break;
            }
        }
        if(flag == 0){                          //flag 값이 안바뀌었으면 호랑이가 먹을 떡이 없다는 뜻
            printf("-1");
            return 0;
        }
    }
    
    for(int i = 0; i < N; i++){
        printf("%d\n", tiger_choice[i]);
    }
    return 0;
}