#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// return string of food order
string solution(vector<int> food) {
    string answer = "";
    // add food to answer by dividing it to half
    for(int i = 1; i < food.size(); i++){
        for(int j = 0; j < food[i] / 2; j++)
            answer += (i + '0');
    }
    // back: string of food order in reverse order
    string back = answer;
    reverse(back.begin(), back.end());

    answer += '0';
    answer += back;
    
    return answer;
}