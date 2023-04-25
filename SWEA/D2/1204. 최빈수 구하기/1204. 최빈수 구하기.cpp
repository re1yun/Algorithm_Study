#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int T;  cin >> T;
    for(int test = 1; test <= T; test++){
        cout << "#" << test << " ";
        int t;  cin >> t;
        map<int, int> studentsTemp;
        for(int i = 0; i < 1000; i++){
            int temp;   cin >> temp;
            if(studentsTemp.find(temp) == studentsTemp.end())
                studentsTemp[temp] = 1;
            else
                studentsTemp[temp]++;
        }
        vector<pair<int, int>> students(studentsTemp.begin(), studentsTemp.end());
        sort(students.begin(), students.end(), [](auto a, auto b){
            if(a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });
        cout << students.begin()->first << endl;
    }
    return 0;
}