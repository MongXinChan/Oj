#include<bits/stdc++.h>  //������C++����ͷ�ļ�

int main(){
    int n;
    std::cin>>n;
    std::string t1,t2,arr[n];
    for (int i = 0; i < n; i++)
         std::cin>>arr[i];
    for (int i = 0; i < n-1; i++){//ѡ������
        for (int j = i+1; j < n; j++){   
            t1=arr[i]+arr[j];  
            t2=arr[j]+arr[i]; 
            if (t1<t2)
               std::swap(arr[i],arr[j]);
        }
    }
    for(int i=0;i<n;i++)
        std::cout<<arr[i];
    return 0;
}
