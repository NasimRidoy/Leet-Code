// For each unique number:

// Check if its neighbors (c-1 and c+1) are in the map.

// If yes, merge the sequences they belong to with the current number.

// Update only the boundary ends of the sequence.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx=0;
        for(auto c:nums)
        {
            if(mp.find(c)==mp.end())
            {
            int left = (mp.find(c-1) == mp.end()) ? 0 : mp[c-1];
            int right = (mp.find(c+1) == mp.end()) ? 0 : mp[c+1];
            mp[c]=left+right+1;
            mx= max(mx, mp[c]);
            mp[c-left] = left+right+1;
            mp[c+right] = left+right+1;
            }
        }
        return mx;
    }
};