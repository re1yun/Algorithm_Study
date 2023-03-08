#include <string>
#include <stack>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    stack<int> score;
    // num: number of darts
    int num = 0;
    for(int i = 0; i < dartResult.length(); i++){
        // if dartResult[i] is a number
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(dartResult[i] == '0')
                num *= 10;
            else
                num = dartResult[i] - '0';
        }
        else if(dartResult[i] == '*' || dartResult[i] == '#'){
            if(dartResult[i] == '*'){
                // if score size is 1, multiply the last element by 2
                if(score.size() == 1){
                    int last = score.top();
                    score.pop();
                    score.push(last * 2);
                }
                // else, multiply the last two elements by 2
                else{
                    int last = score.top();
                    score.pop();
                    int last2 = score.top();
                    score.pop();
                    score.push(last2 * 2);
                    score.push(last * 2);
                }
            }
            else{
                int last = score.top();
                score.pop();
                score.push(last * -1);
            }
        }
        // else, dartResult[i] is 'S', 'D' or 'T'
        else{
            // if dartResult[i] is 'S'
            if(dartResult[i] == 'S'){
                score.push(num);
            }
            // if dartResult[i] is 'D'
            else if(dartResult[i] == 'D'){
                num = num * num;
                score.push(num);
            }
            // else, dartResult[i] is 'T'
            else if(dartResult[i] == 'T'){
                num = num * num * num;
                score.push(num);
            }
            num = 0;
        }
    }
    while(score.empty() == false){
        answer += score.top();
        score.pop();
    }
    return answer;
}