#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    // init
    // vector(x, y) : x sized vector initialized with ys
    vector<vector<int>> triangle(n, vector<int>(n));
    vector<int> answer;
    // r: row, c: col, num: number to be inserted, dir: 0 = down, 1 = right, 2 = up
    int r = 0, c = 0, num = 1, dir = 0;
    
    // algorithm: 
    // n = 4 -> 10, n = 5 -> 15, n = 6 -> 21 thus, n * (n + 1) / 2
    // dir: 0 -> 1 -> 2 -> 0 -> ... until num is smaller than n * (n + 1) / 2
    // step 1: repeat the process until the last number
    while(num <= n * (n + 1) / 2){
        // step 2: insert the number into triangle
        triangle[r][c] = num++;
        // step 3-1: if dir is down, check if it is at bottom or number already exist
        if(dir == 0){
            // if it does, turn right
            if(r == n - 1 || triangle[r + 1][c] != 0){
                dir = 1;
                c++;
            }
            // else, go down
            else{
                r++;
            }
        }
        // step 3-2: if dir is right, check if it is at right end or number already exist
        else if(dir == 1){
            // if it does, turn up
            if(c == n - 1 || triangle[r][c + 1] != 0){
                dir = 2;
                r--;
                c--;
            }
            // else, go right
            else{
                c++;
            }
        }
        // step 3-3: if dir is up, check if it is at top or number already exist
        else if(dir == 2){
            // if it does, turn down
            if(r - 1 == 0 || triangle[r - 1][c - 1] != 0){
                dir = 0;
                r++;
            }
            // else, go up
            else{
                r--;
                c--;
            }
        }
    }
    
    // step 4: create final answer
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < triangle[row].size(); col++) {
            if(triangle[row][col] != 0)
                answer.push_back(triangle[row][col]);
        }
    }

    return answer;
}