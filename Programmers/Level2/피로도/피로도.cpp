/**
 * @file 피로도.cpp
 * @author re1yun (jaeyunlim@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int findDun(int stamina, vector<vector<int>> dungeons, set<int> dungeonSet){
    int maxDungeon = 0;
    // if dungeonSet.size() == dungeon.size(), it means that all dungeons are visited
    if(dungeonSet.size() == dungeons.size())
        return dungeonSet.size();
    // find all dungeons that can be visited
    for(int i = 0; i < dungeons.size(); i++){
        // if it is already visited or cannot be visited, proceed to next dungeon
        if(dungeonSet.find(i) != dungeonSet.end() || stamina < dungeons[i][0])
            continue;
        else{
            dungeonSet.insert(i);
            // see how many dungeons more can be visited
            int temp = findDun(stamina - dungeons[i][1], dungeons, dungeonSet);
            // temp == 0 means that no more dungeons can be visited, thus set temp to current number of dungeons visited
            if(temp == 0){
                temp = dungeonSet.size();
            }
            if(temp > maxDungeon)
                maxDungeon = temp;
            // if there are more dungeons that can be visited, remove the current dungeon from dungeonSet
            if(maxDungeon == dungeons.size())
                return maxDungeon;
            else
                dungeonSet.erase(i);
        }
    }
    return maxDungeon;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    for(int i = 0; i < dungeons.size(); i++){
        // dungeonSet: visited dungeons
        set<int> dungeonSet;
        dungeonSet.insert(i);
        // maxDungeon: max number of dungeons that can be visited
        int maxDungeon = findDun(k - dungeons[i][1], dungeons, dungeonSet);
        if(maxDungeon > answer){
            answer = maxDungeon;
            if(answer == dungeons.size()){
                printf("%d\n", i);
                break;
            }
        }
    }
    return answer;
}