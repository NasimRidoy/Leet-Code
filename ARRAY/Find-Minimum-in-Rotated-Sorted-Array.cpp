class Solution {
public:
    int findMin(vector<int>& nums) {
        int brk = 0;
        int n = nums.size();
        int left = 0, right = n - 1;
        if (nums[0] > nums[n - 1]) {
            while (left <= right) {
                int mid = (left + right) / 2;
                if (nums[mid] > nums[mid + 1]) {
                    brk = mid + 1;
                    break;
                } else if (nums[mid] > nums[right]) {
                    left = mid;
                } else if (nums[mid] < nums[left]) {
                    right = mid;
                }
            }
        }

        return nums[brk];
        
    }
};