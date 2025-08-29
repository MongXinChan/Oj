#include <iostream>
long long dp[3]={0};

long long solution(int A) {
    if(A<=1)return A;
    dp[0]=0,dp[1]=1;
    for(int i=0;i<A;++i){
        long long sum=dp[0]+dp[1];
        dp[0]=dp[1];
        dp[1]=sum;
    }
    return dp[1];
}

int main() {
    // Add your test cases here
    std::cout << (solution(1) == 1) << std::endl;
    std::cout << (solution(5) == 8) << std::endl;
    std::cout << (solution(15) == 987) << std::endl;

    return 0;
}
