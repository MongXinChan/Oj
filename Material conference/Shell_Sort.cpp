# include<iostream>

using namespace std;

const int N = 10005;
int arr[N],n;

void shell_sort(int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2){
        // 可以见到是从插入排序变化而来，增加了gap        
        for(int i=gap;i<n;i++){
            int value=arr[i];
            int j=i-gap;
            while(j>=0&&arr[j]>value){
                arr[j+gap]=arr[j];
                j-=gap;
            }
            arr[j+gap]=value;
        }
    }
}