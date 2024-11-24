class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map <int, int> mp;
        int res = 0;
        for(int n : nums){
            res += mp[n];
            ++mp[n];
        }
        return res;
    }
};
