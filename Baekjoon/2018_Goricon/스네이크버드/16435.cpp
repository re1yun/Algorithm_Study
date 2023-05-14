#include <iostream>
#include <cstdlib>
#include <stdio.h>

#define MAX_FRUIT 1000
using namespace std;

int compare(const void* a, const void* b) {
	const int* x = (int*) a;
	const int* y = (int*) b;
 
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

int eat(int (&fruit)[MAX_FRUIT + 1], int length){
    //int size = sizeof(fruit) / sizeof(int);
    //cout << "size is " << size << "\n";
    int cnt = 0;
    while(cnt <= MAX_FRUIT){
        //cout << length << " " << fruit[cnt] << " " << cnt << "\n";
        if((fruit[cnt] == 0) || (length < fruit[cnt]))
            break;
        else {
            length++;   cnt++;
        }
    }
    return length;
}

int main(){
    int N, L;     cin >> N >> L;
    int fruits[MAX_FRUIT + 1] = {0,};
    for(int i = 0; i < N; i++)
        cin >> fruits[i];
    qsort(fruits, N, sizeof(int), compare);
    
    cout << eat(fruits, L);

    return 0;
}