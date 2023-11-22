#include <iostream>
#include <string>
#include <deque>

using namespace std;

int primeN[101] = { 2, };

int findPrime(int num, int start){
    for(int i = start; i < 10; i++){
        if(primeN[num + i] == 1){
            return i;
        }
    }
    return -1;
}

int main()
{
    int A, B, n;
    scanf("%d %d %d", &A, &B, &n);
    // get all prime numbers until 101
    primeN[1] = 1;
    primeN[2] = 1;
    for (int i = 2; i <= 100; i++){
        if(primeN[i] == 0){
            primeN[i] = 1;
        }
        if(primeN[i] == 1){
            for(int j = i * 2; j <= 100; j += i){
                primeN[j] = 2;
            }
        }
    }

    int check = B / 10;
    if(check != 1 && check != 3 && check != 7 && check != 9){
        printf("-1");
        return 0;
    }
    
    deque<int> s;
    s.push_back(A / 10);
    s.push_back(A % 10);
    int num = 0;
    for(int i = 0; i <= n - 4; i++){
        int temp = s.back() * 10;
        if(i == n - 4){
            num = B / 10;
            if(primeN[temp + num] == 2){
                i -= 2;
                num = s.back() + 1;
                s.pop_back();
                continue;
            }
            else{
                s.push_back(num);
                break;
            }
        }
        int next = findPrime(temp, num);
        if(next == -1){
            if(s.size() == 2){
                printf("-1");
                return 0;
            }
            i -= 2;
            num = s.back() + 1;
            s.pop_back();
        }
        else{
            s.push_back(next);
            num = 0;
        }
    }
    s.push_back(B % 10);
    for(int i = 0; i < s.size(); i++){
        printf("%d", s[i]);
    }
    
    return 0;
}
