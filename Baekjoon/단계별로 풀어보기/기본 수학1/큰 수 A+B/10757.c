#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 10000
int main(){
    char A[10001], A1[10001];
    char B[10001], B1[10001];
    char result[10002] = "";
    int sum = 0, carry = 0;

    scanf("%s %s", &A, &B);
    sprintf(A1, "%010000s", A);
    sprintf(B1, "%010000s", B);

    for(int i = SIZE - 1; i >= 0; i--){
        sum = (A1[i] - '0') + (B1[i] - '0') + carry;
        //sum = A[i] + B[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        result[i + 1] = sum +'0';
    }
    result[0] = carry + '0';
    int i = 0;
    for(i = 0; result[i] == '0'; i++);
    printf("%s", result + i);
    return 0;
}