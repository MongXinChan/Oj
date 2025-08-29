#include <iostream>
#include <string>

int solution(std::string dna1, std::string dna2) {
    // Please write your code here
    if(dna1==dna2){
        return 0;
    }
    int m=dna1.length();
    int n=dna2.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;++i)dp[i][0]=i;
    for(int j=0;j<=n;++j)dp[0][j]=j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dna1[i - 1] == dna2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }

    return dp[m][n];
}

int main() {
    //  You can add more test cases here
    std::cout << (solution("AGCTTAGC", "AGCTAGCT") == 2) << std::endl;
    std::cout << (solution("AGCCGAGC", "GCTAGCT") == 4) << std::endl;
    return 0;
}