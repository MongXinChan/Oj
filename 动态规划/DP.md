# DP

常见类型：

斐波那契，背包问题，打家劫舍，股票问题，子序列问题。

DP数组的含义：状态转移 `dp[i][j]` 下标的含义

递推公式

DP数组初始化

DP数组遍历顺序，有时候是需要先在for循环先i后j，有时候先j后i

打印DP数组

---

[toc]

### 斐波那契数

[509. 斐波那契数 - 力扣（LeetCode）](https://leetcode.cn/problems/fibonacci-number/)

递推思路：

```cpp
class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return fib(n-1)+fib(n-2);
    }
};
```

dp思路：

```cpp
class Solution {
     public:
     int fib(int N) {
     if (N <= 1) return N;
     vector<int> dp(N + 1);
     dp[0] = 0;
     dp[1] = 1;
     for (int i = 2; i <= N; i++) {
     	dp[i] = dp[i - 1] + dp[i - 2];
      }
     return dp[N];
      }
 };
```

- 时间复杂度$O(n)$
- 空间复杂度$O(n)$

```cpp
class Solution{
public:
    int fib(int N){
        if(N<=1)return N;
        int dp[2];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=N;i++){
            int sum=dp[0]+dp[1];
            dp[0]=dp[1];
            dp[1]=sum;
        }
        return dp[1];
    }
};
```

分析：由于计算出来`sum=dp[0]+dp[1]`，而再用`dp[0]=dp[1]`来表示==sum=== ==dp[n]==+dp[n-1]，sum= ==dp[n+1]==+==dp[n]==

- 时间复杂度$O(n)$
- 空间复杂度$O(1)$

---

### 爬楼梯原题

[70. 爬楼梯 - 力扣（LeetCode）](https://leetcode.cn/problems/climbing-stairs/)

1. 确定DP数组以及下标的含义

   DP[i]：爬到第$i$层楼梯，有DP[i]中方法

2. 确定递推公式

   DP[i-1]，上$i-1$层楼梯，有Dp[i-1]种方法，那么再跳1层就是DP[i]了

   DP[i-2]，上$i-2$层楼梯，有Dp[i-2]种方法，那么再跳2层就是Dp[i]。

   Dp[i]=Dp[i-1]+Dp[i-2];

3. 如何初始化

   dp[0]应该如何确定？dp[0]=0，dp[1]=1,dp[2]=2;这种说法也不错

4. 确定遍历顺序

   从递推公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，遍历顺序⼀定是从前向后遍历的

5. 推到dp数组

   ![image-20241125225701662](C:\Users\陈孟欣\AppData\Roaming\Typora\typora-user-images\image-20241125225701662.png)

```cpp
class Solution{
  public:
    int climbStairs(int n){
        if(n<=1)return n;
        vector<int>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
```

- 时间复杂度$O(n)$
- 空间复杂度$O(n)$

跟上面一样的优化套路：

```cpp
class Solution{
  public:
    int climbStairs(int n){
        if(n<=1)return n;
        int dp[3];
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            int sum=dp[1]+dp[2];
            dp[1]=dp[2];
            dp[2]=sum;
        }
        return dp[2];
    }
};
```

- 时间复杂度$O(n)$
- 空间复杂度$O(1)$

注意优化点。

---

一种对爬楼梯的优化情况：

这道题⽬还可以继续深化，就是⼀步⼀个台阶，两个台阶，三个台阶，直到 m个台阶，有多少种⽅法爬到n阶楼 顶。

```cpp
class Solution {
 public:
 int climbStairs(int n) {
 vector<int> dp(n + 1, 0);
 dp[0] = 1;
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= m; j++) { // 把m换成2，就可以AC爬楼梯这道题
if (i - j >= 0) dp[i] += dp[i - j];
  }
  }
 return dp[n];
  }
 };
```

> 代码中m表示最多可以爬m个台阶

---

### <u>最小花费</u>爬楼梯

[746. 使用最小花费爬楼梯 - 力扣（LeetCode）](https://leetcode.cn/problems/min-cost-climbing-stairs/)

>给你一个整数数组 `cost` ，其中 `cost[i]` 是从楼梯第 `i` 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
>
>你可以选择从下标为 `0` 或下标为 `1` 的台阶开始爬楼梯。
>
>请你计算并返回达到楼梯顶部的最低花费。

1. dp数组以及下标的含义

   dp[i]：到达第i阶台阶所花费的最少金币/体力为dp[i]

2. 递推公式

   dp[i]=dp[i-1]+dp[i-2]

   而这里有一个特殊情况，那就是又要考虑到cost[i]的情况：

   dp[i - 1] 跳到 dp[i] 需要花费 dp[i - 1] + cost[i - 1]。  

   dp[i - 2] 跳到 dp[i] 需要花费  dp[i - 2] + cost[i - 2]。

   为了最小化花费我们选择最小的所以dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);

3. dp数组初始化

   dp[0]=0,dp[1]=0;

4. 确定遍历顺序

   > 01背包，都知道两个for循环，⼀个for遍历物品嵌套⼀个for遍历背包容量，那么为什么不是⼀个for遍 历背包容量嵌套⼀个for遍历物品呢？ 以及在使⽤⼀维dp数组的时候遍历背包容量为什么要倒序呢？

5. 举例推导dp数组

   ![image-20241125231701527](C:\Users\陈孟欣\AppData\Roaming\Typora\typora-user-images\image-20241125231701527.png)

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0]=0,dp[1]=0;
        for(int i=2;i<=cost.size();++i){
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};
```

**自己的误区**：我考虑少了min的存在，还有for循环，由于取到的数值`cost.size()+1`是便于`vector`的利用的，我们不用太多`vector`空间。

- 时间复杂度$O(n)$
- 空间复杂度$O(n)$

```cpp
class Solution{
    public:
    int minCostClimbingStairs(vector<int>&cost){
        int dp0=0;
        int dp1=0;
        for(int i=2;i<=cost.size();++i){
            int dpi=min(dp1+cost[i-1],dp0+cost[i-2]);
            dp0=dp1;
            dp1=dpi;
        }
        return dp1;
    }
};
```

- 时间复杂度$O(n)$
- 空间复杂度$O(1)$

----

### 不同路径I

[62. 不同路径 - 力扣（LeetCode）](https://leetcode.cn/problems/unique-paths/)
以下为数论做法：
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int numerator = 1, denominator = 1;
        int count = m - 1;
        int t = m + n - 2;
        while (count--) numerator *= (t--); // 计算分子，此时分子就会溢出
        for (int i = 1; i <= m - 1; i++) denominator *= i; // 计算分母
        return numerator / denominator;
    }
};
```


```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long numerator = 1; // 分子
        int denominator = m - 1; // 分母
        int count = m - 1;
        int t = m + n - 2;
        while (count--) {
            numerator *= (t--);
            while (denominator != 0 && numerator % denominator == 0) {
                numerator /= denominator;
                denominator--;
            }
        }
        return numerator;
    }
};
```


以下为DP做法：
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```


```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 初始化一个大小为 n+1 的数组 f，用于存储到达每个位置的路径数，初始值均为 0
        vector<int> f(n + 1, 0);
        // 将 f[1] 初始化为 1，表示从起点到第一列的第一个位置只有 1 种路径
        f[1] = 1;

        // 遍历每一行
        for (int i = 0; i < m; ++i) {
            // 遍历每一列
            for (int j = 0; j < n; ++j) {
                // 更新 f[j+1] 的值，它等于当前位置上方的路径数 f[j] 和左边的路径数 f[j+1] 之和
                f[j + 1] = f[j] + f[j + 1];
            }
        }

        // 返回到达最后一列的路径数，即 f[n]
        return f[n];
    }
};

```

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n + 1, 0);
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                f[j + 1] = (i == 0 && j == 0) ? 1 : f[j] + f[j + 1];
                //当 i==0&&j==0 时，f[j + 1] 被设置为1，这表示在起点处只有一种路径。
                //在其他情况下，f[j + 1] 的值是通过将当前位置上方的路径数 f[j] 和左边的路径数 f[j + 1] 相加得到的。
        return f[n];
    }
};
```



----

### 货车过路费最优化问题

小C驾驶着货车从A地出发，前往B地，中途经过了多个城市。在这个旅途中，每当小C决定进入一个城市时，他必须缴纳该城市的过路费。而有些城市，小C可以选择跳过，但有一个限制:他不能连续跳过两个城市。

你需要帮助小C计算出在这个旅程中，缴纳过路费的最小总额。已知城市的过路费由一个数组`to11`给出，其中`to11[i]`表示第$i$个城市(不包括起点和终点)的过路费。

**约束条件**

1. 小C可以选择跳过部分城市，但不能连续跳过两个城市。
2. 起点城市和终点城市的过路费不计入计算。

```cpp
#include <iostream>
#include <vector>

int solution(std::vector<int>& toll) {
    // write code here
    int dp[toll.size()+1];
    return 0;
}

int main() {
    std::vector<int> toll1 = std::vector<int>{1, 2, 3};
    std::cout << (solution(toll1) == 2) << std::endl;

    std::vector<int> toll2 = std::vector<int>{5, 10, 3, 1, 6};
    std::cout << (solution(toll2) == 9) << std::endl;

    std::vector<int> toll3 = std::vector<int>{4, 6, 8};
    std::cout << (solution(toll3) == 6) << std::endl;
    return 0;
}
```

