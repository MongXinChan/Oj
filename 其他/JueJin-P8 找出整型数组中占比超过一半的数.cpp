#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    // Edit your code here
    int cand=0;
    int count=0;
    for(int num:array){
        if(count==0){
            cand=num;
            count++;
        }else{
            if(num==cand){
                count++;
            }else{
                count--;
            }
        }
    }
    return cand;
}

int main() {
    // Add your test cases here
    
    cout << (solution({1, 3, 8, 2, 3, 1, 3, 3, 3}) == 3) << endl;
    
    return 0;
}
