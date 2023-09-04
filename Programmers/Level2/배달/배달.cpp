#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    // init
    int answer = 0;
    // map: road info in 2D vector
    vector<vector<int>> map(N, vector<int>(N, 0));
    for(vector<int> road_info : road){
        int vil1 = road_info[0] - 1, vil2 = road_info[1] - 1, dist = road_info[2];
        if(map[vil1][vil2] != 0 && map[vil1][vil2] < dist){
            continue;
        }
        map[vil1][vil2] = dist;
        map[vil2][vil1] = dist;
    }
    // pq: priority queue containing distance and village -> (distance, village)
    // s_map: shortest distance to a village from village 1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> s_map(N, 999999999);
    pq.push(make_pair(0, 0));
    s_map[0] = 0;
    // dijkstra algorithm to get s_map
    while(!pq.empty()) {
        int dis = pq.top().first;
        int vil = pq.top().second;
        pq.pop();
 
        if(s_map[vil] < dis){
            continue;
        }
        
        for(int i = 0; i < N; i++){
            if(vil != i && map[vil][i] != 0 && s_map[i] > map[vil][i] + dis){
                s_map[i] = map[vil][i] + dis;
                pq.push(make_pair(s_map[i], i));
            }
        }
    }
    
    // algorithm: search all possible points from 1st village using BFS...but it doesn't work as each village's minimum distance should be used when they are startingV
    for(int i = 0; i < N; i++){
        if(s_map[i] <= K)
            answer++;
    }
    
    return answer;
}