class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        int dirs[8][2] = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int live = 0;

                for(auto &d:dirs){
                    int r=i+d[0];
                    int c=j+d[1];

                    if(r>=0 && r<m && c>=0 && c<n &&
                       abs(board[r][c])==1)
                        live++;
                }

                if(board[i][j]==1 && (live<2 || live>3))
                    board[i][j] = -1;

                if(board[i][j]==0 && live==3)
                    board[i][j] = 2;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};