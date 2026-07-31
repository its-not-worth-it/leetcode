class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>> adj(n, vector<int>(n,1e9));
        for(vector<int> &i: edges){
            adj[i[0]][i[1]]=i[2];
            adj[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]= min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
        int ans=0, t=n, x;
        for(int i=0;i<n; i++){
            x=n-1;
            for(int j=0;j<n;j++){
                if(i!=j and adj[i][j] > d) x--;
            }
            // cout<<i<<" "<<x<<endl;
            if(t==x){
                ans=i;
            }else if(t > x){
                ans=i;
                t=x;
            }
        }
        return ans;
    }
};