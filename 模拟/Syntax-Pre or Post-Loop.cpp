#include<iostream>
using namespace std;
int main(){
  cout<<"PreOrder:";
  for(int i=0;i<10;++i)cout<<i;
  cout<<endl;<<"PostOrder:";
  for(int i=0;i<10;i++)cout<<i;
  return 0;
}
