//decending monotone stack

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        int i = 0;
        
        while (i < height.size()){
            if (stk.empty() || height[i] <= height[stk.top()]) stk.push(i++);
            else{
                int curr = stk.top();
                stk.pop();
                
                if (stk.empty()) continue;//! because one bar is not trapping any water
                int h = min(height[stk.top()], height[i]) - height[curr];
                int w = i - 1 - stk.top();
                res += h * w;
            }
        }
        return res;

    }
};
