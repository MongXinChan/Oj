class Solution {
    public:
        string decodeString(string s) {
            stack<pair<string, int>> st; // <左括号之前的字符串，上一个数字>
            int num = 0;
            string res;
            for(char c : s){
                if(c>='0' && c<='9'){ // 数字
                    num = num * 10 + (c - '0'); // 注意数字可能不止一位
                }
                else if(c == '['){ // 左括号
                    st.push(make_pair(res, num));
                    res = "";
                    num = 0; // 复原res和num
                }
                else if(c == ']'){ // 右括号
                    string pre = st.top().first; // 当前左括号之前的字符串
                    int n = st.top().second; // 当前左括号前的数字
                    string cur; // 当前左右括号内的字符串
                    for(int i = 0; i < n; i++){
                        cur += res; // cur需要乘n次
                    }
                    res = pre + cur; // 到目前为止的结果
                    st.pop();
                }
                else{ // 普通字符
                    res += c;
                }
            }
            return res;
        }
    };