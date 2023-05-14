#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int br, bc, dr, dc, jr, jc;
    scanf("%d %d", &br, &bc);
    scanf("%d %d", &dr, &dc);
    scanf("%d %d", &jr, &jc);
    int daisy = abs(jr - dr) + abs(jc - dc);
    int bessie = sqrt(pow((jr - br), 2) + pow((jc - bc), 2));
    if(bessie < daisy)
    printf("bessie");
    else if(bessie > daisy)
    printf("daisy");
    else
    printf("tie");
    return 0;
}