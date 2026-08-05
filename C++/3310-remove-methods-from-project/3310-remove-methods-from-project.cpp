class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(auto i: invocations){
            graph[i[0]].push_back(i[1]);
        }
        queue<int> q;
        vector<bool> vis(n,false);
        vis[k]=true; q.push(k); int x;
        while(!q.empty()){
            x=q.front(); q.pop();
            for(int i: graph[x]){
                if(!vis[i]) {
                    vis[i]=true;
                    q.push(i);
                }
            }
        }
        vector<int> ans; ans.reserve(n);
        for(int i=0;i<n;i++){
            if(!vis[i]) {q.push(i); ans.push_back(i); vis[i]=true;}
            else vis[i]=false;
        }
        
        while(!q.empty()){
            x=q.front(); q.pop();
            for(int i: graph[x]){
                if(!vis[i]) {
                    for(int j=0;j<n;j++){
                        if(!vis[j]) ans.push_back(j);
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
};