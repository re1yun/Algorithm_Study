#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> answer;
    // temp: nums in asc order
    vector<int> temp(nums.begin(), nums.end());
    sort(temp.begin(), temp.end());
    int leftIdx = 0, rightIdx = nums.size() - 1;
    
    // algorithm
    int sum = temp[leftIdx] + temp[rightIdx];
    while(sum != target){
        if(sum < target) 
            leftIdx++;
        else if(sum > target)
            rightIdx--;
        sum = temp[leftIdx] + temp[rightIdx];
    }
    
    // if two numbers are same,
    if(temp[leftIdx] == temp[rightIdx]){
        // find first occuring number, and seach next
        auto it = find(nums.begin(), nums.end(), temp[leftIdx]);
        answer.push_back(it - nums.begin());
        answer.push_back(find(it + 1, nums.end(), temp[rightIdx]) - nums.begin());
    }
    // else, just find and insert
    else{
        answer.push_back(find(nums.begin(), nums.end(), temp[leftIdx]) - nums.begin());
        answer.push_back(find(nums.begin(), nums.end(), temp[rightIdx]) - nums.begin());
    }

    return answer;
}