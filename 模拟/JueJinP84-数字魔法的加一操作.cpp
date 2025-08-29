#include <iostream>
#include <string>

short a[1000] = {0};
int solution(int n, int k, std::string num_str) {
  // Please write your code here
  const int MOD = 1000000007;
  while (k--) {
    std::string s = "";
    for (int i = 0; i < num_str.length(); ++i) {
      a[i] =
          num_str[i] - '0' +
          1; // 做这里的时候我在想要不要+1，最后是决定用，判定是否大于10，直接追加到新字符里;
    }
    for (int i = 0; i < num_str.length(); ++i) {
      if (a[i] == 10) {
        s += "10";
        continue;
      }
      s += std::to_string(a[i]);
    }
    num_str = s;
  }
  long long result = 0;
  for (char c : num_str) {
    result = ((result * 10) + (c - '0')) % MOD;
  }
  return result;
}

int main() {
  // You can add more test cases here
  std::cout << (solution(3, 1, "798") ) << std::endl;
  std::cout << (solution(3, 3, "798") == 103221) << std::endl;

  return 0;
}