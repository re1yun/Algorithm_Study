#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    // setup game queue
    queue<int> game[board.size()];
    for(vector<int> v : board){
        for(int i = 0; i < v.size(); i++){
            game[i].push(v[i]);
        }
    }
    // play game
    stack<int> basket;
    for(int move : moves){
        int doll = 0;
        while(true){
            if(game[move - 1].empty()) break;
            doll = game[move - 1].front();
            game[move - 1].pop();
            if(doll == 0) continue;
            else break;
        }
        if(doll == 0) continue;
        if(basket.empty())
            basket.push(doll);
        else{
            if(basket.top() == doll){
                basket.pop();
                answer += 2;
            }
            else
                basket.push(doll);
        }
    }

    return answer;
}