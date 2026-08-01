class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // if(n==1) return time[0];

        vector<int> indegree(n+1,0); indegree[0]=1;
        vector<vector<int>> adj(n+1);
        for(auto i: relations){
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        // for(int i:indegree) cout<<i<<" ";

        vector<int> temp(n+1,0);
        for(int i=1;i<n+1;i++) temp[i]=time[i-1];

        queue<int> q; 
        for(int i=1;i<n+1;i++) if(indegree[i]==0) q.push(i);
        int ans=time[q.front()-1], x;

        while(!q.empty()){
            x=q.front(); q.pop();
            ans=max(ans, temp[x]);
            for(int i: adj[x]){
                indegree[i]--;
                temp[i]=max(temp[i], temp[x]+time[i-1]);
                if(!indegree[i]) q.push(i);
            }
        }
        return ans;

    }
};