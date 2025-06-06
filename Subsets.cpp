class Solution {
public:
    
    // it has two choice for each element.
    // either-
    //     take it  or,
    //     ignore it
    // so it becomes a binary tree. for each element you either take or leave it.
    // time complexity: O(2^n)
    //     as for each elements 2 choice: 2*2*2*2......
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>ans;
        createSubset(nums, 0, subset, ans);
        return ans;
        
    }
    void createSubset(vector<int>& nums, int cur_ind, vector<int>&current, vector<vector<int>>&ans)
    {
        if(cur_ind == nums.size())
        {
            ans.push_back(current);
            return;

        }
        current.push_back(nums[cur_ind]); //including current element
        createSubset(nums, cur_ind+1, current, ans);
        current.pop_back(); //excluding current element. backtracking
        return createSubset(nums, cur_ind+1, current, ans);
    }
};