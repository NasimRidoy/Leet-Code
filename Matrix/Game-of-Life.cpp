class Solution {
public:
    int liveNeighbour(vector<vector<int>>& board, int m, int n, int i, int j)
    {
        int live=0;
        for(int x=max(i-1,0);x<=min(i+1,m-1);x++)
        {
            for(int y=max(j-1,0);y<=min(j+1,n-1);y++)
            {
                live+=(board[x][y] & 1);    //{next state, current state}
            }
        }
        live-=(board[i][j] & 1); //exclude self if counted
        return live;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>>res;
        int live;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                live = liveNeighbour(board, row, col, i, j);
                //0 to 00, 1 to 01 not needed
                //only modify if next state is 1
                if((board[i][j]&1) == 1 && (live >=2 && live <=3)) 
                    board[i][j]=3; //binary 11
                else if((board[i][j]&1) == 0 && live==3)
                    board[i][j]=2; //binary 10

                //cout<<"live"<<" "<<live<<" "<<i<<j;
            }
            cout<<endl;
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                board[i][j]>>=1; //excluding current bit
            }
        }
    return;
    }
};