#include <iostream>
#include <vector>
using namespace std;

bool solution(vector<vector<int>>& points) {
    if(points[0]==points[1]||points[1]==points[2]||points[0]==points[2]){
        return false;
    }
    int x1=points[0][0],y1=points[0][1];
    int x2=points[1][0],y2=points[1][1];
    int x3=points[2][0],y3=points[2][1];
    if((y2-y1)*(x3-x2)==(y3-y2)*(x2-x1)){
        return false;
    }
    // write code here
    return true;
}

int main() {
    vector<vector<int>> v1 = {{1, 1}, {2, 3}, {3, 2}};
    vector<vector<int>> v2 = {{1, 1}, {2, 2}, {3, 3}};
    vector<vector<int>> v3 = {{0, 0}, {1, 1}, {1, 0}};

    cout << (solution(v1) == true) << endl;
    cout << (solution(v2) == false) << endl;
    cout << (solution(v3) == true) << endl;
    return 0;
}