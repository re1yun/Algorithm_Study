#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int solution(string word) {
    // init
    int answer = 0;
    unordered_map<char, int> index = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};
    unordered_map<int, int> count = {{0, pow(5, 4)}, {1, pow(5, 3)}, {2, pow(5, 2)}, {3, pow(5, 1)}, {4, 1}};
    // algorithm
    for(int i = 0; i < word.size(); i++){
        for(int j = i; j < 5; j++){
            answer += (index[word[i]] * count[j]);
        }
        answer++;
    }
    return answer;
}