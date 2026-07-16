class Solution {
public:
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size(), m=c[0].size();
        vector<vector<int>> t(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=j and c[i][j]){
                    t[i].push_back(j);
                }
            }
        }
        vector<bool> vis(n,false); int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                for(int j:t[i]) dfs(t,vis,j);
                ans++;
            }
        }


        return ans;
    }
    void dfs(vector<vector<int>> &t, vector<bool> &vis, int i){
        if(!vis[i]){
            vis[i]=true;
            for(int j:t[i]) dfs(t,vis,j);
        }
    }
};