# DP

常见类型：

斐波那契，背包问题，打家劫舍，股票问题，子序列问题。

DP数组的含义：状态转移 `dp[i][j]` 下标的含义

递推公式

DP数组初始化

DP数组遍历顺序，有时候是需要先在for循环先i后j，有时候先j后i

打印DP数组

---

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

