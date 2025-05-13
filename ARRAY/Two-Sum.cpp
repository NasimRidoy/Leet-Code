class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (mp.count(rem)) {
                if (i != mp[rem]) {
                    res[0] = i;
                    res[1] = mp[rem];
                    return res;
                }
            }
        }
        return res;
    }
};