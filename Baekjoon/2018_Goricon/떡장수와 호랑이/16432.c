#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int date[1001] = { 0, };
int ddeuk[1000][10];
int visit[1000][10];
int tiger_choice[1001] = {0, };
int flag = 0;

void dfs(int c_date, int before){    //c_date는 오늘이 몇번째 날인지, before는 어제 먹은 떡의 종류를 나타냄
    if(c_date == N){
        flag = 1;
        return;
    }

    for(int i = 1; i <= 9; i++){  //date[c_date]오늘 가진 떡의 개수
        if(ddeuk[c_date][i] == 1 && i != before && visit[c_date][i] == 0){  //떡이 값이 있고, i가 종류가 다르며 방문하지 않은 곳
            visit[c_date][i] = 1;
            tiger_choice[c_date] = i;   //답에 일단 추가
            dfs(c_date + 1, i);         //재귀 실행
            if(flag == 1){              //재귀가 끝나고 방법을 찾았다면 포문을 나가라
                break;
            }
            tiger_choice[c_date] = 0;   //재귀가 끝났는데 방법이 없다. 그럼 다시 정답 reset
        }
    }
}

int main(){
    scanf("%d%*c", &N);
    for(int i = 0; i < N; i++){
        char message[500];
        gets(message);
        date[i] = atoi(message);
        for(int j = 0; j <= date[i]; j++){
            if(j == 0){
                ddeuk[i][atoi(strtok(message, " "))] = 0;
            }
            else{
                ddeuk[i][atoi(strtok(NULL, " "))] = 1;
            }
        }
    }
    memset(visit, 0, sizeof(visit));
    dfs(0, 0);

    if(flag == 1){
        for(int i = 0; i < N; i++){
            printf("%d\n", tiger_choice[i]);
        }
    }
    else{
        printf("-1");
    }
    
    return 0;
}