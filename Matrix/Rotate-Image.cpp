class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=row;
        int i,j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(i<j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(i=0;i<row;i++)
        {
            int left=0,right=col-1;
            while(left<=right)
            {
                swap(matrix[i][left++],matrix[i][right--]);
            }
        }
        return;
    }
};