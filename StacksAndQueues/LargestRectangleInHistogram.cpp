/*
Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Largest Rectangle in Histogram: Example 1

http://i.imgur.com/1OutEEI.png

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

http://i.imgur.com/F2bePvG.png

Largest Rectangle in Histogram: Example 2

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
*/

int Solution::largestRectangleArea(vector<int> &hist) {
    stack<int> s; 
    int max_area = 0;
    int tp;
    int area_with_top; 
    int i = 0; 
    while (i < hist.size()) { 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++);
        else { 
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    }
    while (s.empty() == false) { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    }
    return max_area; 
} 



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;
        
        for(int i = 0; i <= n; i++){
            int currHeight = i == n ? 0 : heights[i];
            // check if currHeight becomes greater then height[top] element of stack. we do a push because it's an increasing sequence
            // otherwise we do pop and find area, so for that we write a while loop
            while(!st.empty() && currHeight < heights[st.top()]){
                int top = st.top(); st.pop(); // current element on which we are working
                // now we need width & area
                int width = st.empty() ? i : i - st.top() - 1; // width differ if we stack is empty or not empty after we pop the element// 
                int area = heights[top] * width; // current height * width
                maxArea = max(area, maxArea);
            }
            // if it doesn't enter in while loop, it means it's an increasing sequence & we need to push index
            st.push(i);
        }
        return maxArea;
    }
};
// i-s.top -1
// i = leftmost guy
// s.top = rigthmost guy and -1 is for excluded bar
