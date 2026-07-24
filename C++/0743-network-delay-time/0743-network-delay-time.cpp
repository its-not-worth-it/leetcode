class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> g;
        for(vector<int> i:times){
            g[i[0]].push_back({i[1],i[2]});
        }
        set<pair<int,int>> pq;
        pq.insert({0,k});
        vector<int> dist(n+1,1e9); dist[0]=-1; dist[k]=0;
        while(!pq.empty()){
            int td=pq.begin()->first, node=pq.begin()->second;
            pq.erase(pq.begin());
            for(auto it: g[node]){
                if(td+it.second < dist[it.first]){
                    if(dist[it.first] != 1e9){
                        pq.erase({dist[it.first],it.first});
                    }
                    dist[it.first]=td+it.second;
                    pq.insert({dist[it.first],it.first});
                }
            }
        }
        int m=*max_element(dist.begin(),dist.end());
        return m==1e9?-1:m;
    }
};