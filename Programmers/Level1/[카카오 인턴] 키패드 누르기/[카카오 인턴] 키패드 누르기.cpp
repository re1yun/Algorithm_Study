#include <string>
#include <vector>
#include <iostream>

using namespace std;

// return position of value on number pad
vector<int> position(int value){
    vector<int> pos;
    // if value is 0
    if(value == 0){
        pos.push_back(3);
        pos.push_back(1);
    }
    // if value is 10
    else if(value == 11){
pos.push_back(3);
        pos.push_back(2);
}
    // if value is 1 ~ 9
    else{
        pos.push_back((value - 1) / 3);
        pos.push_back((value - 1) % 3);
    }
    return pos;
    
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    // define number pad
    int pad[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 0, 12}};
    // define left and right hand position
    vector<int> left = position(10);
    vector<int> right = position(11);
    // define left and right hand distance
    int left_dist, right_dist;
    
    for(int i = 0; i < numbers.size(); i++){
        // if number is 1, 4, 7
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            left = position(numbers[i]);
        }
        // if number is 3, 6, 9
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            right = position(numbers[i]);
        }
        // if number is 2, 5, 8, 0
        else{
            // find position of number
            vector<int> num = position(numbers[i]);
            // find left hand distance
            left_dist = abs(left[0] - num[0]) + abs(left[1] - num[1]);
            // find right hand distance
            right_dist = abs(right[0] - num[0]) + abs(right[1] - num[1]);
            // if left hand distance is shorter than right hand distance
            if(left_dist < right_dist){
                answer += "L";
                left = position(numbers[i]);
            }
            // if left hand distance is longer than right hand distance
            else if(left_dist > right_dist){
                answer += "R";
                right = position(numbers[i]);
            }
            // if left hand distance is same as right hand distance
            else{
                // if hand is left
                if(hand == "left"){
                    answer += "L";
                    left = position(numbers[i]);
                }
                // if hand is right
                else{
                    answer += "R";
                    right = position(numbers[i]);
                }
            }
        }
    }

    return answer;
}