class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> g;
        for(vector<int> i:times){
            g[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,k});
        vector<int> dist(n+1,1e9); dist[0]=-1; dist[k]=0;
        while(!pq.empty()){
            int td=pq.top().first, node=pq.top().second;
            pq.pop();
            for(auto it: g[node]){
                if(td+it.second < dist[it.first]){
                    dist[it.first]=td+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int m=*max_element(dist.begin(),dist.end());
        return m==1e9?-1:m;
    }
};