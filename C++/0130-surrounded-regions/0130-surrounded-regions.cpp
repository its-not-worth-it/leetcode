class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n=b.size(), m=b[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,true));
        for(int i=0;i<n;i++){
            if(b[i][0]=='O' ) q.push({i,0});
            if( b[i][m-1] =='O') q.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            if(b[0][j]=='O' ) q.push({0,j});
            if( b[n-1][j] =='O') q.push({n-1,j});
        }
        int x, y, l, h;
        vector<int> vt{-1,1,0,0}, hz{0,0,-1,1};
        while(!q.empty()){
            x=q.front().first; y=q.front().second; q.pop();
            vis[x][y]=false;
            for(int i=0;i<4;i++){
                l=x+vt[i]; h=hz[i]+y;
                if(l>=0 and l<n and h>=0 and h<m and vis[l][h] and b[l][h]=='O'){
                    vis[l][h]=false;
                    q.push({l,h});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]) b[i][j]='X';
            }
        }
    }
};