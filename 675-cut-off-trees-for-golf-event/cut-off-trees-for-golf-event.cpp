class Solution {
public:

    int bfs(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {

        int m = forest.size();
        int n = forest[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited(m, vector<int>(n,0));

        q.push({sr,sc});
        visited[sr][sc] = 1;

        int steps = 0;

        vector<int> dir = {0,1,0,-1,0};

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                auto [r,c] = q.front();
                q.pop();

                if(r == tr && c == tc)
                    return steps;

                for(int i=0;i<4;i++) {

                    int nr = r + dir[i];
                    int nc = c + dir[i+1];

                    if(nr>=0 && nc>=0 && nr<m && nc<n
                       && !visited[nr][nc]
                       && forest[nr][nc]!=0) {

                        visited[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }

            steps++;
        }

        return -1;
    }


    int cutOffTree(vector<vector<int>>& forest) {

        int m = forest.size();
        int n = forest[0].size();

        vector<tuple<int,int,int>> trees;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(forest[i][j] > 1)
                    trees.push_back({forest[i][j],i,j});
            }
        }

        sort(trees.begin(), trees.end());

        int sr = 0, sc = 0;
        int totalSteps = 0;

        for(auto &[h,r,c] : trees) {

            int steps = bfs(forest, sr, sc, r, c);

            if(steps == -1)
                return -1;

            totalSteps += steps;

            sr = r;
            sc = c;
        }

        return totalSteps;
    }
};