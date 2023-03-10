#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size() / 2;
    // erase duplicates of nums
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    // if nums.size() is less than or equal to original nums.size() / 2
    if(nums.size() <= n)
        answer = nums.size();
    // else, nums.size() is greater than original nums.size()
    else
        answer = n;
    return answer;
}