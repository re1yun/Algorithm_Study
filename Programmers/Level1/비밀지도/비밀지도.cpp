#include <string>
#include <vector>

using namespace std;

// return secret map
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    // use bit operator 'or' to get full map
    for(int i = 0; i < n; i++){
        int num = arr1[i] | arr2[i];
        // convert row into 2bit
        string row = "";
        for(int j = n - 1; j >= 0; j--){
            int temp = (num >> j) & 1;
            if(temp == 1)
                row += '#';
            else
                row += ' ';
        }
        answer.push_back(row);
    }
    return answer;
}