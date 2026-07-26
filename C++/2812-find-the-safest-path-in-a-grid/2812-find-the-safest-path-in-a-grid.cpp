class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(grid[0][0]==1 or grid[n-1][m-1]==1) return 0;

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    q.push({i,j});
                }else grid[i][j]=-1;
            }
        }
        vector<int> vt{-1,1,0,0}, hz{0,0,1,-1};
        int x,y,z, l,r;

        while(!q.empty()){
            x=q.front().first; y=q.front().second; q.pop();
            for(int i=0;i<4;i++){
                l=x+vt[i]; r=y+hz[i];
                if(l<n and r<m and l>=0 and r>=0 and grid[l][r]==-1){
                    grid[l][r]=grid[x][y]+1;
                    q.push({l,r});
                }
            }
        }

        priority_queue< array<int,3> >pq;
        vector<vector<bool>> vis(n, vector<bool>(m,false)); vis[0][0]=true;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            x=pq.top()[1]; y=pq.top()[2]; z=pq.top()[0]; pq.pop();
            if(x==n-1 and y==m-1) break;

            for(int i=0;i<4;i++){
                l=x+vt[i]; r=y+hz[i];
                if(l<n and r<m and l>=0 and r>=0 and !vis[l][r] ){
                    vis[l][r]=true;
                    grid[l][r]= min(grid[x][y], grid[l][r]);
                    pq.push({grid[l][r], l, r});
                }
            }
        }

        return grid[n-1][m-1];
    }
};