class Solution {
public:

    //count frequency in a hashmap
    //store frequency as index and the elements as values in a vector
    //iterate from end of the vector and take first k elements
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        vector<vector<int>> freq(nums.size() + 1);
        for (auto pair : mp) {
            freq[pair.second].push_back(pair.first);
        }
        vector<int> ans;
        for (int i = freq.size() - 1; i >= 0; i--) {
            for (int val : freq[i]) {
                if (k)
                {
                    ans.push_back(val);
                    k--;
                }
            }
        }
        return ans;
    }
};