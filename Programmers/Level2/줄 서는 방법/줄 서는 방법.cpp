#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    // init
    vector<int> answer, people;
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }
    
    // algorithm: find all possible permutations and return kth permutation !!! X took too long
    // algorithm: using factorial, find which number comes at kth permutation, as all numbers are in ascending order
    while (answer.size() < n) {
        long long number = factorial(people.size() - 1);
        for (int i = 1; i <= people.size(); i++) {
            if (i * number >= k) {
                answer.push_back(people[i - 1]);
                people.erase(people.begin() + i - 1);
                k -= ((i - 1) * number);
                break;
            }
        }
    }

    return answer;
}
