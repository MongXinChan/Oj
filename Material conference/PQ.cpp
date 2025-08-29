#include<bits/stdc++.h>

using namespace std;

int main(){
    priority_queue<pair<int,string>> pq;//大根堆
    pair<int,string> a(11,"Peking"),b(10,"Nanking"),c(21,"Teochew");

    pq.push(a);
    pq.push(b);
    pq.push(c);
    while(!pq.empty()){
        auto t=pq.top();
        cout<<t.first<<" "<<t.second<<endl;
        pq.pop();
    }

    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq2;//小根堆
    pq2.push(a);
    pq2.push(b);
    pq2.push(c);
    while(!pq2.empty()){
        auto t=pq2.top();
        cout<<t.first<<" "<<t.second<<endl;
        pq2.pop();
    }
    return 0;
}