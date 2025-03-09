#include <iostream>

using namespace std;

class stack
{
private:
	int t;
	int *s;
	int capacity;
public:
	stack(int capacity){
        this->capacity = capacity;
        s = new int[capacity];
        t=-1;
    }
	~stack(){
        delete []s;
    }
	void push(int x){
        s[++t]=x;
    }
	int pop(){
        if(t==-1){
            return -1;
        }else{
            return s[t--];
        }
    }
	int top(){
        if (t==-1){
            return -1;	
        }
        return s[t];
    }
	bool Empty(){
        if(t==-1){
            return 1;	
        }else{
            return 0;
        }
    }
	void display(){
        for(int i=t;i>=0;i--){
            cout<<s[i]<<" ";	
        }
    }
};

int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout<<s.top()<<endl;
    std::cout<<s.pop()<<endl;
    s.display();
    return 0;
}