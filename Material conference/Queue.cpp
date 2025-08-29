#include<iostream>

const int N = 10005;
struct Queue{
    int data[N];
    int head,tail;
    Queue():head(0),tail(0){}
    void push(int x){
        if((tail+1)%N==head){
            std::cout<<"Queue Full\n";
            return;
        }
        data[tail]=x;
        tail=(tail+1)%N;
    }
    void pop(){
        if(head==tail){
            std::cout<<"Queue Empty\n";
            return;
        }
        head=(head+1)%N;
    }
    int front(){
        if(head==tail){
            std::cout<<"Queue Empty\n";
            return -1;
        }
        return data[head];
    }
    bool empty(){
        return head==tail;
    }
}