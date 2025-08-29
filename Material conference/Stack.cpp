#include <iostream?

using namespace std;

const int N = 10005;
struct Stack{
    int data[N];
    int top;
    Stack():top(-1){}//从0开始，-1的意思是空栈
    void push(int x){
        if(top == N-1){
            cout<<"Stack Full\n";
            return;
        }
        data[top++]=x;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack Empty\n";
            return;
        }
        top--;
    }
    int top(){
        if(top == -1){
            cout<<"Stack Empty\n";
            return -1;
        }
        return data[top]; 
    }
    bool empty(){
        return top == -1;
    }
    int size(){
        return top+1 ;
    }
};