/**
 * @file 기능개발.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int days = 0;
    for(int i = 0; i < progresses.size(); i++){
        days += (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0){
            days++;
        }
        int count = 1;
        for(int j = i + 1; j < progresses.size(); j++){
            progresses[j] = progresses[j] + speeds[j] * days;
            if(progresses[j] >= 100){
                count++;
                i++;
            }
            else{
                break;
            }
        }
        answer.push_back(count);
    }
    return answer;
}