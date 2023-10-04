#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    // init
    int answer = 1;
    vector<vector<int>> map(n, vector<int>(n, 0));
    for(vector<int> edg : edge){
        map[edg[0] - 1][edg[1] - 1] = 1;
        map[edg[1] - 1][edg[0] - 1] = 1;
    }
    vector<int> dijk(n, 20001);
    vector<int> check(n, 0);
    dijk[0] = 0;
    check[0] = 1;
    
    // algorithm: use dijkstra and sort() to find number of max nodes
    // step 1: define queue to store node to travel next
    queue<int> q;
    q.push(0);
    // step 2: travel until q is empty
    while(!q.empty()){
        int start = q.front();
        q.pop();
        // step 3: run the row to find which ones are connected
        for(int i = 0; i < n; i++){
            if(map[start][i] == 1){
                // step 4: if connected nodes are found, check if current distnace is minimum
                dijk[i] = (dijk[i] < dijk[start] + 1) ? dijk[i] : dijk[start] + 1;
                // step 5: if the node has not been visited, add to queue and mark as checked
                if(check[i] == 0){
                    q.push(i);
                    check[i] = 1;
                }
            }
        }
    }
    
    // step 6: sort descending and find number of maximum distance nodes
    sort(dijk.begin(), dijk.end(), greater<int>());
    int max = dijk[0];
    for(int i = 1; i < dijk.size(); i++){
        if(dijk[i] == max){
            answer++;
        }
        else 
            break;
    }
    return answer;
}