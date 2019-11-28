//monotone stack O(n): acceding (store index): the bar with the lowest height trigger the searching for max area

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int mx = 0;
        heights.push_back(0); //help to process the last bar
        
        for (int i = 0; i < heights.size(); ++i){
            if (stk.empty() || heights[i] >= heights[stk.top()]) { // keep pushing if the heights are in accending order
                stk.push(i);
            } else{
                int curr = stk.top(); 
                stk.pop();
                
                int width = stk.empty() ? i : (i - 1 - stk.top()); //move the stk.top() to the left each time, we need the area between (the bar adjacent to the i-th bar) and (the bar we just popped).
                mx = max(mx, heights[curr] * width);
                --i; //!
            }
        }
        return mx;
    }
};
