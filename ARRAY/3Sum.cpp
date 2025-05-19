class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if(i>0 && nums[i] == nums[i-1]  )
                continue;
            int l = i + 1;
            int r = nums.size() - 1;
            int rem = -1 * nums[i];
            while (l < r) {
                int total = nums[l] + nums[r] + nums[i];
                if (total == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                        {l++;}
                }
                else if (total > 0) {
                    r--;
                } else if(total < 0){
                    l++;
                }
            }
        }
        return res;
    }
};