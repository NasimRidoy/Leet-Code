class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(int i=0;i<strs.size();i++)
        {
            int ara[26]={0};
            for(int j=0;j<strs[i].size();j++)
            {
                ara[strs[i][j] - 'a']++;
            }
            string key = "";
            for(int j=0;j<26;j++)
            {
                key+=(to_string(ara[j])+"*");
            }
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for(auto x : mp)
        {
            res.push_back(x.second);
        }
        return res;
    }
};