class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        vector<int> ans; ans.reserve(n); vector<bool> vis(n,false), pvis(n,false);
        for(vector<int> i:p){
            graph[i[1]].emplace_back(i[0]);
        }
        bool f=false;
        for(int i=0;i<n;i++){
            if(!vis[i]) f=help(graph,vis,pvis,i,-1);
            if(f) {
                return {};
            }
        }
        for(int i=0;i<n;i++) vis[i]=false;
        
        for(int i=0;i<n;i++){
            if(!vis[i]) helper(graph,vis,ans,i);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
    void helper(vector<vector<int>> &graph, vector<bool> &vis, vector<int> &ans, int i){
        vis[i]=true;
        for(int j:graph[i]){
            if(!vis[j]) helper(graph,vis,ans,j);
        }
        ans.push_back(i);
    }
    bool help(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pvis, int i, int p){
        vis[i]=true; pvis[i]=true;
        for(int j:graph[i]){
            if(!vis[j]) {
                if(help(graph,vis,pvis,j,i)) return true;
            }else if(vis[j] and pvis[j] ) return true;
        }
        pvis[i]=false;
        return false;
    }
};