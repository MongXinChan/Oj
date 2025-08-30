# include<iostream>
# include<pair>
# include<vector>
# include<algorithm>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // 初始化最大值为根节点
    int left = 2 * i + 1; // 左子节点索引
    int right = 2 * i + 2; // 右子节点索引

    // 如果左子节点比根节点大
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点比当前最大值还大
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值不是根节点，交换并递归堆化受影响的子树
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(vector<int>& arr) {
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 一个个从堆中取出元素
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // 将当前最大值移到数组末尾
        heapify(arr, i, 0); // 重新堆化剩余元素
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heap_sort(arr);
    cout << "Sorted array is \n";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}