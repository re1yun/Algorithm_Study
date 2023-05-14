#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_LENGTH 100001
char buf[BUF_LENGTH];
char num[10][30] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int sign[BUF_LENGTH];

int main(){
    int cnt = 0, realnumcnt = 0;
    int signcnt = 0;
    scanf("%s", &buf);
    int length = strlen(buf);
    int index = 0, index2 = 0;
    char tmp[10];   //비교될 문자 저장할 배열
    int num[7] = {0,};  //실제 자리 숫자가 저장될 배열
    int realnum[10] = {0, };    //진짜 숫자들    
    int sign[10];          //사칙연산 저장할 배열
    int ans = 0;        //최종 값
    memset(tmp, NULL, sizeof(tmp));
    while(index != length){
        if(buf[index] == '+' || buf[index] == '-' || buf[index] == '*' || buf[index] == '/' || buf[index] == '='){
            for(int i = cnt; i >= 0; i--){
                realnum[realnumcnt++] += num[i] * pow(10, i);
            }
            sign[signcnt++] = buf[index];
            index++;
            if(buf[index] == '+' || buf[index] == '-' || buf[index] == '*' || buf[index] == '/' || buf[index] == '='){
                printf("Madness!");
                return 0;
            }
        }
        tmp[index2++] = buf[index++];   //tmp에 하나씩 저장
        for(int i = 0; i < 10; i++){    //tmp와 숫자문자들 비교
            if(strcmp(tmp, num[i]) == 0){       //만약 같다면,
                num[cnt++] = i;                 //자리 값의 실제 수 저장
                index2 = 0;                     //tmp 다시 시작
                memset(tmp, NULL, sizeof(tmp)); //tmp 리셋
                break;
            }
        }
        if(index2 > 5){     //숫자 문자열 아님
            printf("Madness!");
            return 0;
        }
    }
    
    for(int i = 0; i < realnumcnt; i++){
        printf("%d%c", realnum[i], sign[i]);
    }

    return 0;
}
/*

int calc = 0;
            for(int i = cnt; i >= 0; i--){
                calc += num[i] * pow(10, i);
            }
            switch(buf[index]){
                case 43:    //+
                    ans += calc;
                    break;
                case 45:    //-
                    ans -= calc;
                    break;
                case 42:    //*
                    ans = ans * calc;
                    break;
                case 47:    // /
                    ans = ans / calc;
                    break;
                case 61:    // =
                    break;
            }*/