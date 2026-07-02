class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size() , m=grid[0].size();
        deque<pair<int,int>> d;
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        vis[0][0]=grid[0][0];
        d.push_front({0,0});
        int r,c,row, col, w, dirr[]={-1,1,0,0}, dirc[]={0,0,1,-1};
        while(!d.empty()){
            r=d.front().first;
            c=d.front().second;
            d.pop_front();
            if(r==n-1 and c==m-1) break;

            for(int i=0;i<4;i++){
                row=r+dirr[i]; col=dirc[i]+c;
                if(row<n and row>=0 and col>=0 and col<m){
                    if(vis[r][c]+grid[row][col]< vis[row][col]){
                        vis[row][col]=vis[r][c]+grid[row][col];

                        if(grid[row][col]==0) d.push_front({row,col});
                        else d.push_back({row,col});
                    }
                }
            }
        }

        return vis[n-1][m-1] < health;
    }
};