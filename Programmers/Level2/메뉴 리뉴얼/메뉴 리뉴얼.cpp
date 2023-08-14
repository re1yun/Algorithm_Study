#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// use DFS
void getMenu(map<string, int>& menus, string &temp, string order, int index, int num_menu){
    if(temp.size() == num_menu){
        menus[temp]++;
        return;
    }
    for(int i = index; i < order.size(); i++){
        temp += order[i];
        getMenu(menus, temp, order, i + 1, num_menu);
        temp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    // init
    vector<string> answer;
    map<string, int> menus;
    
    // algorithm: find all possible combination of orders and count the most frequent combination
    // step 1: run through orders
    for(int i = 0; i < orders.size(); i++){
        // step 2: sort the orders to make sure they are in order
        sort(orders[i].begin(), orders[i].end());
        // step 3: run through coures
        for(int j = 0; j < course.size(); j++){
            string temp = "";
            getMenu(menus, temp, orders[i], 0, course[j]);
        }
    }
    
    // step 4: get most menus
    vector<pair<string, int>> temp;
    for(pair<string, int> menu : menus){
        temp.push_back(make_pair(menu.first, menu.second));
    }
    sort(temp.begin(), temp.end(), [](auto& a, auto& b){
        if(a.first.size() == b.first.size()){
            return a.second > b.second;
        }
        return a.first.size() < b.first.size();
    });
    
    string res = temp[0].first;
    int max_cnt = temp[0].second;
    for(pair<string, int> tem : temp){
        if(res.size() == tem.first.size() && max_cnt == tem.second){
            answer.push_back(tem.first);
        }
        else if(res.size() != tem.first.size() && tem.second > 1){
            res = tem.first;
            max_cnt = tem.second;
            answer.push_back(tem.first);
        }
        else{
            continue;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}