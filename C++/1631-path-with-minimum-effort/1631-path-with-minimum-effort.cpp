class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n= h.size(), m=h[0].size(); vector<vector<int>> vis(n,vector<int>(m,1e9));
        priority_queue<array<int,3>, vector<array<int,3>> , greater<array<int,3>> > pq;
        pq.push({0,0,0}); vis[0][0]=0;
        vector<int> vt{-1,1,0,0}, hz{0,0,-1,1};
        int x, y, z, r, l;
        while(!pq.empty()){
            x=pq.top()[1]; y=pq.top()[2]; z=pq.top()[0];
            pq.pop();
            for(int i=0;i<4; i++){
                l=x+vt[i]; r=y+hz[i];
                if(l>=0 and r>=0 and l<n and r<m and vis[l][r] > max(z, abs(h[x][y]-h[l][r]) )){
                    vis[l][r]=max(z, abs(h[x][y]-h[l][r]) );
                    pq.push({vis[l][r],l,r});
                }
            }
        }
        
        return vis[n-1][m-1];
    }
};