#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char message[1001];
    scanf("%s", &message);
    int length = strlen(message);
    //printf("length : %d", length);
    if(length < 5){
        printf("not cute");
    }
    else{
        if(message[length - 5] == 'd' && message[length - 4] == 'r' && message[length - 3] == 'i' && message[length - 2] == 'i' && message[length - 1] == 'p'){
            printf("cute");
        }
        else{
            printf("not cute");
        }
    }
    return 0;
}