#include <vector>
#include <algorithm>

using namespace std;

// return lowest sum of multiplication of each number of A and B
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    // sort A ascending order, B descending order
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for(int i = 0; i < A.size(); i++){
        answer += (A[i] * B[i]);
    }
    return answer;
}