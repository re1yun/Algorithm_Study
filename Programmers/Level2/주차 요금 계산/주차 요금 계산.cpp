/**
 * @file 주차 요금 계산.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    // init
    vector<int> answer;
    unordered_map<string, int> car;
    unordered_map<string, int> car_total_time;
    unordered_map<string, int> car_fee;
    // calculate total time
    for(string s: records){
        int car_time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        string car_num = s.substr(6, 4);
        string car_state = s.substr(11, 2);
        // if car enters, add to car
        if(car_state == "IN"){
            car[car_num] = car_time;
        }
        // else car exits, remove the car
        else{
            int time = car_time - car[car_num];
            car_total_time[car_num] += time;
            car.erase(car_num);
        }
    }
    // if car is still in parking lot, assume it exits at 23:59
    int exit_time = 23 * 60 + 59;
    for(auto it = car.begin(); it != car.end(); it++){
        car_total_time[it->first] += (exit_time - it->second);
    }
    // calculate fee
    for(auto it = car_total_time.begin(); it != car_total_time.end(); it++){
        int time = it->second;
        // if time is less than fees[0], fee is fees[1]
        if(time <= fees[0]){
            car_fee[it->first] = fees[1];
        }
        // else, fee is fees[1] + (time - fees[0] - 1) / fees[2] * fees[3]
        else{
            double temp = (double)(time - fees[0]) / (double)fees[2];
            int fee = ceil(temp) * fees[3] + fees[1];
            car_fee[it->first] = fee;
        }
    }
    // sort by car number
    vector<string> car_num;
    for(auto it = car_fee.begin(); it != car_fee.end(); it++){
        car_num.push_back(it->first);
    }
    sort(car_num.begin(), car_num.end());
    // return answer
    for(string s: car_num){
        answer.push_back(car_fee[s]);
    }
    return answer;
}