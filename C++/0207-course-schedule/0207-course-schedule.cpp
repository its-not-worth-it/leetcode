class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n,false), pvis(n,false);
        for(vector<int> i:p){
            graph[i[1]].emplace_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i] and help(graph,vis,pvis,i,-1) ) return false;
            
        }
        

        return true;
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