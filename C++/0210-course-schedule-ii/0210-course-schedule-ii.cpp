class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        vector<int> ans; ans.reserve(n); vector<bool> vis(n,false), pvis(n,false);
        for(vector<int> i:p){
            graph[i[1]].emplace_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i] and help(graph,ans,vis,pvis,i,-1) ) return {};
            
        }
        

        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    bool help(vector<vector<int>> &graph,vector<int> &ans, vector<bool> &vis, vector<bool> &pvis, int i, int p){
        vis[i]=true; pvis[i]=true;
        for(int j:graph[i]){
            if(!vis[j]) {
                if(help(graph,ans,vis,pvis,j,i)) return true;
            }else if(vis[j] and pvis[j] ) return true;
        }
        pvis[i]=false;
        ans.push_back(i);
        return false;
    }
};