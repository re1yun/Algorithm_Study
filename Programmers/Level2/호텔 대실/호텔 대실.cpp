#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    // init
    
    // algorithm: since all inputs are in time sequence, they should be converted into minutes and added into queues or use vectors
    // step 1: convert time strings into minute values
    vector<vector<int>> book_time_int;
    for(vector<string> time: book_time){
        vector<int> time_int;
        for(int i = 0; i < 2; i++){
            int temp1 = stoi(time[i].substr(0, 2));
            int temp2 = stoi(time[i].substr(3, 2));
            time_int.push_back(temp1 * 60 + temp2);
        }
        time_int[1] += 10;
        book_time_int.push_back(time_int);
    }
    
    // step 2: sort them based on the starting book time
    sort(book_time_int.begin(), book_time_int.end());
    
    // step 3: put each book into a room based on the starting book time
    vector<int> hotel;
    for(vector<int> time: book_time_int){
        int dif = 999999, room_number = -1;
        // step 3-1: check all hotel room
        for(int i = 0; i < hotel.size(); i++){
            // if starting book time is bigger than ending book time and difference is minimum
            if(hotel[i] <= time[0] && time[0] - hotel[i] < dif){
                // update difference and room_number
                dif = time[0] - hotel[i];
                room_number = i;
            }
        }
        // step 3-2: if room number has updated, update hotel room
        if(room_number != -1){
            hotel[room_number] = time[1];
        }
        // step 3-3: if room number has not updated, add new hotel room
        else{
            hotel.push_back(time[1]);
        }
    }

    return hotel.size();
}