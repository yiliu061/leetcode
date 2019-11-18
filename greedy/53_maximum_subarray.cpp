/*
link:
https://leetcode.com/problems/maximum-subarray/

problem description:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/


// greedy, O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int global_max = nums[0];
        int local_max = 0;  //don't use INT_MIN or nums[0] here, because we are going to add nums[0] to it

        for (int num : nums){
            local_max = max(local_max + num, num);
            global_max = max(global_max, local_max);
        }

        return global_max;
    }
};

