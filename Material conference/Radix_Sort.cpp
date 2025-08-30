# include<iostream>

using namespace std;

void Radix_sort(int arr[],int n){
    int max_val=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max_val)
            max_val=arr[i];
    }
    //确定最大值的位数
    int max_digit=0;
    while(max_val){
        max_digit++;
        max_val/=10;
    }

    int exp=1;//表示当前位数对应的数值
    int output[n];//输出数组
    for(int d=0;d<max_digit;d++){
        int count[10]={0};//计数数组，范围是0-9

        //计算每个桶中的元素个数
        for(int i=0;i<n;i++){
            int digit=(arr[i]/exp)%10;
            count[digit]++;
        }

        //将count[i]改为count[i]包含了小于等于i的元素个数
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }

        //构建输出数组
        for(int i=n-1;i>=0;i--){
            int digit=(arr[i]/exp)%10;
            output[count[digit]-1]=arr[i];
            count[digit]--;
        }

        //将输出数组复制回原数组
        for(int i=0;i<n;i++){
            arr[i]=output[i];
        }

        exp*=10;//处理下一位
    }
}