#include <string>
#include <vector>

using namespace std;

// return number of prime numbers less than or equal to n, using eratostenes sieve
int solution(int n) {
    int answer = 0;
    int prime[n + 1];
    for(int i = 2; i <= n; i++)
        prime[i] = i;
    
    for(int i = 2; i <= n; i++){
        if(prime[i] == 0)
            continue;
        for(int j = 2 * i; j <= n; j += i){
            prime[j] = 0;
        }
    }
    for(int i = 2; i <= n; i++){
        if(prime[i] != 0)
            answer++;
    }
    return answer;
}