void permute(vector<int>& arr, int start) {
    // 递归终止条件：当 start 达到数组末尾，说明我们已经找到了一个完整的排列
    if (start == arr.size()) {
        for (int x : arr) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    // 遍历所有可能的元素，将其放在当前位置
    for (int i = start; i < arr.size(); ++i) {
        // 1. 将 arr[i] 放到当前位置 arr[start]
        swap(arr[start], arr[i]);

        // 2. 递归处理剩下的元素
        permute(arr, start + 1);

        // 3. 回溯：恢复数组到交换前的状态，以尝试其他可能性
        swap(arr[start], arr[i]);
    }
}
