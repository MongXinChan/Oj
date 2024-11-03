#include<iostream>
#define MAXN 423399 //如果没加(int)会出现size of array 'arr' has non-intergral type 'double'
int arr[MAXN];

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(){
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<n;)std::cin>>arr[i++];
    quickSort(arr,0,n);
    std::cout<<arr[m];
    return 0;
}
