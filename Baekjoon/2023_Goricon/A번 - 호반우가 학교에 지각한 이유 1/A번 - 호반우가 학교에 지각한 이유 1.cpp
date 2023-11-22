#include <iostream>

using namespace std;

int main()
{
    int STR, DEX, INT, LUK, n;
    scanf("%d %d %d %d %d", &STR, &DEX, &INT, &LUK, &n);
    int sum = STR + DEX + INT + LUK;
    int total = n * 4;
    printf("%d", sum <= total ? total - sum : 0);
    return 0;
}