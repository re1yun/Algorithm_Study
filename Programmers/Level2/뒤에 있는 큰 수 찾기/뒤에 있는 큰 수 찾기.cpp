#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // init
    // answer is initialized with all -1 values for the size of numbers
    vector<int> answer(numbers.size(), -1);
    
    // iterate backwards, although last value is already set to -1, so don't need to compute
    for(int i = numbers.size() - 2; i >= 0; i--){
        for(int j = i + 1; j < numbers.size(); j++){
            // if next number is bigger, save the value into answer
            if(numbers[i] < numbers[j]){
                answer[i] = numbers[j];
                break;
            }
            // else if next number is equal or smaller,
            else{
                // if saved value is -1, that means you can't find bigger number
                if(answer[j] == -1){
                    answer[i] = -1;
                    break;
                }
                // else if saved number is bigger than current number, save that number
                else if(numbers[i] < answer[j]){
                    answer[i] = answer[j];
                    break;
                }
                // else, continue iterate forward
            }
        }
    }
    return answer;
}