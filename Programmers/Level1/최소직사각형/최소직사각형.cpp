#include <string>
#include <vector>

using namespace std;

// return size of longest length and height
int solution(vector<vector<int>> sizes) {
    int length = 0, height = 0;
    for(vector<int> size : sizes){
        int row = (size[0] > size[1] ? size[0] : size[1]);
        int col = (row == size[0] ? size[1] : size[0]);
        if(length < row)
            length = row;
        if(height < col)
            height = col;
    }
    return length * height;
}