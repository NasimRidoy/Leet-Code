class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=INT_MIN;
        int sum=0;
        int starti=0, endi = nums.size()-1,temps=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mx)
            {
                mx = sum;
                starti = temps;
                endi = i;
            }        
            if(sum<0)
            {
                sum=0;
                temps=i+1;
            }
                
        }
        cout<<starti<<\ \<<endi<<endl;
        return mx;
    }
};