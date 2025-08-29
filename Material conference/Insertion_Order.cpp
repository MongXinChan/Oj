# include <iostream>

using namespace std;

const int N = 10005;
int arr[N],n;

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int value=arr[i];
        int j=i-1;
        //寻找插入位置
        while(j>=0&&arr[j]>value){
            arr[j+1]=arr[j];//数据后移
            j--;
        }
        arr[j+1]=value;//插入
    }
}