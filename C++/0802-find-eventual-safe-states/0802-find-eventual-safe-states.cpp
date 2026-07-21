class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n),pvis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]) help(graph,vis,pvis,i);
        }
        vector<int> ans; ans.reserve(n);
        for(int i=0;i<n;i++) if(!pvis[i]) ans.push_back(i);
        return ans;
    }
    bool help(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pvis, int i){
        vis[i]=true; pvis[i]=true; bool f=false;
        for(int j:graph[i]){
            if(!vis[j] ) f=f|help(graph,vis,pvis,j);
            else if(vis[j] and pvis[j]) f=true;
        }
        if(!f) pvis[i]=false;

        return f;
    }
};