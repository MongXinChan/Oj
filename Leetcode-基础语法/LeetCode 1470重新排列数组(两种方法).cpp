class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //考虑到2n个元素
        //vector怎么对半取是一个问题
        for(int i=0;i<2*n;i++){
            int j=i<n?2 *i:2*(i-n)+1;
            nums[j] |=(nums[i]&1023)<<10;
        }
        for(int&e:nums)e>>=10;
        return nums;
    }
};

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[i + n];
        }
        return ans;
    }
};

