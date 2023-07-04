#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n == 0 || n == 1) return false; // 0과 1은 소수가 아님
    for (int i = 2; i * i <= n; i++) { // 2부터 제곱근까지 나누어 떨어지는 수가 있다면 소수가 아님
        if (n % i == 0) {
            return false;
        }
    }
    return true; // 그 외의 경우 소수임
}

vector<int> posNumbers(string numbers){
    vector<int> allNumbers, num;
    for(int i = 0; i < numbers.size(); i++)
        num.push_back(numbers[i] - '0');
    sort(num.begin(), num.end());
    
    for(int L = 1; L <= numbers.size(); L++){ // 1부터 numbers.size()까지 순회(L은 만들 숫자의 자리수)
        do{
            int n = 0; // 숫자의 값을 계산할 변수
            for(int i = 0; i < L; i++){
                n = n * 10 + num[i]; // num 벡터에서 값을 가져와 n 변수에 계속 더함
            }
            if(is_prime(n)){
                if(find(allNumbers.begin(), allNumbers.end(), n) == allNumbers.end())
                    allNumbers.push_back(n); // prime number인 경우 allNumbers에 추가
            }
                
        }while(next_permutation(num.begin(), num.end()));
    }
    
    return allNumbers;
}

int solution(string numbers) {
    // init
    int answer = 0;
    vector<int> allNumbers;
    
    // algorithm
    // step 1. create all possible numbers in bruteforce
    allNumbers = posNumbers(numbers);
    
    answer = allNumbers.size();
    return answer;
}