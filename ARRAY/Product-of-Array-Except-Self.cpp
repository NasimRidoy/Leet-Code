class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int sz = nums.size();
        //vector<int> prefix(sz), suffix(sz);
        //prefix[0]=1,suffix[sz-1]=1;
        vector<int>res(sz);
        int pref=1,suff=1;
        for (int i = 0; i < sz; i++) {
            res[i] = pref;
            pref*=nums[i];
        }
        
        for(int j=sz-1;j>=0;j--)
        {
            res[j]*= suff;
            suff*=nums[j];
        }
        return res;
    }
};