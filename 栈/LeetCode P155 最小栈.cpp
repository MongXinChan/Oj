class MinStack {
    public:
        stack<long> dist;
        long min_s;
        MinStack() : min_s(0) {}
        // 初始化一个变量来存储最小值
        
        void push(int val) {
            if (dist.empty()) {
                //判断是否为空，为空则直接赋值;
                min_s = val;
                dist.push(0);
            } else {
                long diff = val - min_s;
                // 计算差值
                dist.push(diff);
                // 入栈差值的原因是因为我们只需要知道最小值的变化，而不需要知道具体的值;；
                // 当 diff > 0 时，说明当前入栈的值比之前的最小值大，因此我们不需要更新最小值;；
                min_s = diff > 0 ? min_s : val;
                // 更新最小值
            }
        }
        
        void pop() {
            if (!dist.empty()) {
                // 出栈时，我们需要更新最小值;；
                // 当 diff > 0 时，说明当前出栈的值比之前的最小值大，因此我们不需要更新最小值;；
                long diff = dist.top();
                dist.pop();
                min_s = diff > 0 ? min_s : min_s - diff;
            }
        }
        
        int top() {
            if (dist.empty()) {
                return -1;
            } else {
                long diff = dist.top();
                if (diff > 0) {
                    return (diff + min_s);
                } else {
                    return min_s;
                }
            }
        }
        
        int getMin() {
            if (dist.empty()) {
                return -1;
            } else {
                return min_s;
            }
        }
    };