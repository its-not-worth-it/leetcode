class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> dist(n,1e12); vector<int> ways(n, 0);
        dist[0]=0; ways[0]=1;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &i: roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
        pq.push({0,0});
        long long a; int b, mod=1e9+7;

        while(!pq.empty()){
            a=pq.top().first; b=pq.top().second;    pq.pop();

            for(pair<int,int> &i: adj[b]){
                if(dist[i.first]== a+i.second){
                    ways[i.first]= (ways[i.first]+ways[b]) % mod;
                }else if(dist[i.first] > a+i.second){
                    ways[i.first]= ways[b];
                    dist[i.first]= a+i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }

        return ways[n-1]% mod;
    }
};