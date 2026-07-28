class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        auto comp=[](const array<int,3> &a, const array<int,3> &b){
            if(a[0]==b[0] and a[1]==b[1]) return a[2]<b[2];
            else if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        };
        priority_queue<array<int, 3>, vector<array<int,3>>, decltype(comp) > pq(comp);
        pq.push({grid[0][0], 0, 0});
        int n=grid.size();
        vector<vector<int>> vis(n, vector<int>(n,-1));  vis[0][0]=grid[0][0];

        vector<int> vt{-1,1,0,0}, hz{0,0,-1,1};
        int x, y, z, l, h;

        while(!pq.empty()){
            x=pq.top()[1]; y=pq.top()[2]; z=pq.top()[0];    pq.pop();
            if(x==n-1 and y==n-1) break;
            for(int i=0;i<4;i++){
                l=x+vt[i]; h=y+hz[i];
                if(l>=0 and h>=0 and l<n and h<n and (vis[l][h]==-1 or vis[l][h] > max(vis[x][y], grid[l][h])) ){
                    vis[l][h]=max(vis[x][y], grid[l][h]);
                    // cout<<vis[l][h]<<" "<<l<<" "<<h<<endl;
                    pq.push({vis[l][h], l, h});
                }
            }
        }
        return vis[n-1][n-1];
    }
};