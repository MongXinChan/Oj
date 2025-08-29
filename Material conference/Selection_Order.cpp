#include <iostream>

using namespace std;

const int N = 10005;
int arr[N],n;

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        //寻找[i,n)中的最小值
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index])
                min_index=j;
                //更新最小值的下标
        }
        if(min_index!=i)
            swap(arr[i],arr[min_index]);
    }
}