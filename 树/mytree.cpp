#include <iostream>
using namespace std;
const int N = 100;

struct Dynamic_Node
{
	int data;
	Dynamic_Node *left;
	Dynamic_Node *right;
};

/**/
struct Static_Node{
	int data;
	int left;
	int right;
}t[N];

void print(int u){
    if(u){
        cout<<u<<" ";
        print(t[u].left);
        print(t[u].right);
    }
}

void printable(Static_Node t[],int root){
	if(t[root].left!=-1){
		printable(t,t[root].left);
	}
	cout<<t[root].data<<" ";
	if(t[root].right!=-1){
		printable(t,t[root].right);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].data>>t[i].left>>t[i].right;
	}
	printable(t,1);
	return 0;	
}