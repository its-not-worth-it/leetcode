class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<array<int,3>, vector<array<int,3>> , greater<array<int,3>>> pq;
        pq.push({0,k+1,src});
        int a, b, c;
        vector<vector<int>> ans(n,vector<int>(k+1,-1)); ans[src][k]=0;

        while(!pq.empty()){
            a=pq.top()[0]; b=pq.top()[1]; c=pq.top()[2];  pq.pop();
            if(b==0) continue;
            for(pair<int,int> &i: adj[c]){
                if(ans[i.first][b-1]==-1 or ans[i.first][b-1] > a+i.second ){
                    ans[i.first][b-1]= a+i.second;
                    pq.push({ans[i.first][b-1], b-1, i.first});
                    // cout<<ans[i.first]<<" "<<b-1<<" "<<i.first<<endl;
                }
            }
        }
        // for(int i:ans) cout<<i<<" ";
        int x=1e9;
        for(int &i:ans[dst]){
            if(i!=-1) x=min(x,i);
        }
        return x==1e9? -1: x;
    }
};