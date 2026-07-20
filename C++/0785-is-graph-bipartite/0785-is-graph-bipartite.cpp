class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size(), x;
        vector<int> color(n,-1); 
        queue<int> q; 
        for(int i=0;i<n;i++){
            if(color[i]!=-1) continue;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                for(int i:g[q.front()]){
                    if(color[i]==-1){
                        color[i]=!color[q.front()];
                        q.push(i);
                    }else{
                        if(color[i]==color[q.front()]) return false;
                    }
                }
                q.pop();
            }
        }
        return true;
    }
};