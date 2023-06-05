#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights){
    // init
    // trucks: weight of trucks, bridge: current state of bridge
    int answer = 1;
    deque<int> trucks(truck_weights.begin(), truck_weights.end());
    deque<pair<int, int>> bridge;
    bridge.push_back(make_pair(trucks.front(), 0));
    trucks.pop_front();
    
    // algorithm
    while(bridge.size() != 0){
        // first, increase distance of trucks on bridge
        int sum = 0;
        for(int i = 0; i < bridge.size(); i++){
            bridge[i].second++;
            sum += bridge[i].first;
        }
        // second, remove trucks that reached the end of truck and/or add new truck
        // if first truck reached the end of bridge, remove
        if(bridge.front().second == bridge_length){
            sum -= bridge[0].first;
            bridge.pop_front();
        }
        // total weight of trucks on bridge is lower than limit, add truck
        if(sum + trucks.front() <= weight && trucks.size() != 0){
            bridge.push_back(make_pair(trucks.front(), 0));
            trucks.pop_front();
        }
        answer++;
    }
    return answer;
}