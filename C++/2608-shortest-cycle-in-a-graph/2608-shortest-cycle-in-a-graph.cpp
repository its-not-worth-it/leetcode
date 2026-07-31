class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int> &i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans=-1, t;
        queue<int> q;
        for(int k=0;k<n;k++){
            vector<int> vis(n, -1);
            vis[k]=0;
            q.push(k);
            while(!q.empty()){
                t=q.front(); q.pop();
                for(int i: adj[t]){
                    if(vis[i]==-1){
                        vis[i]=vis[t]+1;
                        q.push(i);
                    }else if(vis[i] >= vis[t]){
                        if(ans==-1){
                            ans=vis[i]+vis[t]+1;
                        }else ans=min(ans, vis[i]+ vis[t]+1);
                    }
                }
            }
        
        }
        return ans;
    }
};