class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> prefix(sz), suffix(sz);
        prefix[0]=1,suffix[sz-1]=1;
        for (int i = 1,j=sz-2; i < sz && j>=0; i++,j--) {
            prefix[i]=prefix[i-1]*nums[i-1];
            suffix[j]=suffix[j+1]*nums[j+1];
        }
        vector<int>res(sz);
        for(int i=0;i<sz;i++)
        {
            res[i]=prefix[i]*suffix[i];
        }
        return res;
    }
};