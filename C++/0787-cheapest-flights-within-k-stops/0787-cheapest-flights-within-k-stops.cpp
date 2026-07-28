class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<array<int,3>, vector<array<int,3>> , greater<array<int,3>>> pq;
        pq.push({0,0,src});
        int a, b, c;
        vector<int> ans(n,1e9); 

        while(!pq.empty()){
            a=pq.top()[0]; b=pq.top()[1]; c=pq.top()[2];  pq.pop();
            if(b > k+1) continue;
            if(c==dst) return a;
            if(b >= ans[c]) continue;
            ans[c]=b;
            for(auto x: adj[c]){
                pq.push({a+x.second, b+1, x.first});
            }
        }
        
        return -1;
    }
};