//在有序的半段里search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) return mid;

            if (nums[mid] > nums[right]) {//左半段有序
                if ((target < nums[mid]) && (target >= nums[left])) right = mid - 1;
                else left = mid + 1; 
            }
            else if(nums[mid] < nums[left]){//右半段有序
                if ((target > nums[mid]) && (target <= nums[right]) ) left = mid + 1;
                else right = mid - 1;
            }
            else{// no rotation
                if (target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            } 
                
        }
        return -1;
    }
};
