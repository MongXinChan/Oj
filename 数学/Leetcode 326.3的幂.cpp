class Solution {
    public:
        bool isPowerOfThree(int n) {
            return n > 0 && 1162261467 % n == 0;
            //因为注意到int最高为2^32,而2^19<2^32<3^20
            //如果这是一道比赛题目，可以写个循环算出来！！
        }
    };
    