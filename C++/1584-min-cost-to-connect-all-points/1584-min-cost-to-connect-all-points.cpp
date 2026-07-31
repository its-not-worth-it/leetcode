class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> w(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                w[i][j]=abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                w[j][i]=w[i][j];
            }
        }

        int ans=0;
        vector<bool> vis(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,0});

        int node, weight;
        while(!pq.empty()){
            node=pq.top().second; weight=pq.top().first; pq.pop();

            if(vis[node]) continue;

            vis[node]=true;
            ans+=weight;

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    pq.push({w[node][i], i});
                }
            }
        }
        return ans;
    }
};