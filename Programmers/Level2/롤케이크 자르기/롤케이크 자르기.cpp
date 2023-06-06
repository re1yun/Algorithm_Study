#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    // init
    // left, right: variable to store toppings
    int answer = 0;
    unordered_map<int, int> left, right;
    int rightIdx = topping.size() - 1;
    
    // algorithm
    // save all topping variation to left
    for(int top : topping)
        left[top]++;
    // repeat until leftIdx is equal or bigger than rightIdx
    while(left.size() >= right.size()){
        // count the topping
        right[topping[rightIdx]]++;
        left[topping[rightIdx]]--;
        // if topping is gone at left, erase it
        if(left[topping[rightIdx]] == 0)
            left.erase(topping[rightIdx]);
        // if variation of topping is same, increase answer
        if(left.size() == right.size()){
            answer++;
        }
        rightIdx--;
    }
    
    return answer;
}