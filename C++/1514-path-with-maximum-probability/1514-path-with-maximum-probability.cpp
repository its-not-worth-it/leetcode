class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<(int)edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        set<pair<double, int> , greater<pair<double, int>> > s;    s.emplace(1.0,start_node);
        vector<double> dist(n,0); dist[start_node]=1;
        while(!s.empty()){
            double td=s.begin()->first; int node=s.begin()->second;
            s.erase(s.begin());
            for(auto it: adj[node]){
                if( (td*it.second) > dist[it.first]){
                    if(dist[it.first] !=0 ){
                        s.erase({dist[it.first], it.first});
                    }
                    dist[it.first]=td * it.second;
                    s.emplace(dist[it.first],it.first);
                }
            }
        }
        return dist[end_node];
    }
};