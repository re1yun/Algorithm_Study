#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int year;
    int month;
    int day;
}DATE;

int main(){
    DATE S, E, W;
    scanf("%d %d %d", &S.year, &S.month, &S.day);
    scanf("%d %d %d", &E.year, &E.month, &E.day);
    int total, monthly, yearly;
    memset(&W, 0, sizeof(W));
    W.day = E.day - S.day;
    if(W.day < 0){
        W.month--;
        W.day = 30 + W.day;
    }
    W.month += (E.month - S.month);
    if(W.month < 0){
        W.year--;
        W.month = 12 + W.month;
    }
    W.year += (E.year - S.year);
    total = W.day + W.month * 30 + W.year * 12 * 30;
yearly = 0;
    if(W.year >= 3){
        monthly = 36;
        int year = 1;
        while(year <= W.year){
            if(year % 2 == 0 ){
                int A = year / 2 - 1;
                yearly += (A + 15);
            }
            else{
                int A = year / 2;
                yearly += (A + 15);
            }
            year++;
        }
    }
    else{
        int year = 0;
        yearly = W.year * 15;
        monthly = W.year * 12 + W.month;
    }

    printf("%d %d\n", yearly, monthly);
    printf("%ddays", total);
    return 0;
}