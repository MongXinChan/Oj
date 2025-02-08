class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int>hashtable;
            //unordered_map位键值对的集合，按照键生成散列，键是唯一的
            for(int i=0;i<nums.size();++i){
                auto it=hashtable.find(target-nums[i]);
                //在hash表中查询是否存在target-nums[i]的数值
                if(it!=hashtable.end()){
                    //如果存在，返回两个数字的下标
                    //it—>first是键
                    //it->second是值
                    /*
                it->second：在哈希表中，it->second 是键值对的值部分。
                在这个问题中，值部分存储的是数组中某个元素的索引。
                it->first：是键部分，表示数组中的某个值（nums[i]）。
                    */
                    return {it->second,i};
                }
                hashtable[nums[i]]=i;
            }
            return {};
        }
    };