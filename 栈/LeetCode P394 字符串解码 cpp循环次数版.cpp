class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int n = 0;
        // 记录循环的次数，记录的不是循环的字符串而是它前面的字符串，循环完拼接起来
        stack<pair<int, string>> st;
        for(char c : s){
            if(c == '['){
                st.push({n, res});
                res = "";// 重置字符串和计数
                n = 0;
            }
            else if(c == ']'){
                string temp = "";
                for(int i = 0; i < st.top().first; i++) temp += res;
                res = st.top().second + temp;//循环完拼接起来
                st.pop();
            }
            else if(c >= '0' && c <= '9') 
                n = n * 10 + (c - '0'); //防止出现两位数，三位数
            else
                res += c;
        }
        return res;
    }
};