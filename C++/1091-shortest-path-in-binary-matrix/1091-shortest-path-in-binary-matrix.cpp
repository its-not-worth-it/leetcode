class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(); vector<vector<bool>> vis(n,vector<bool>(n,0));
        if(grid[0][0]==0) {q.push({0,0}); vis[0][0]=true;}
        vector<int> vt{-1,1,-1,1,0,0,-1,1}, hz{1,-1,0,0,1,-1,-1,1};
        int ans=1;
        while(!q.empty()){
            int m=q.size();
            while(m--){
                int x=q.front().first, y=q.front().second; q.pop();
                if(x==y and x==n-1) return ans;
                for(int i=0;i<8;i++){
                    int l=x+vt[i], h=y+hz[i];
                    if(l>=0 and h>=0 and l<n and h<n and grid[l][h]==0 and !vis[l][h]){ 
                        q.push({l,h}); vis[l][h]=true;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};