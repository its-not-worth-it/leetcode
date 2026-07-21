class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> indegree(n);    vector<vector<int>> nodes(n);
        for(vector<int> i:p){
            indegree[i[0]]++;
            nodes[i[1]].emplace_back(i[0]);
        }
        vector<int> ans; ans.reserve(n);
        queue<int> q; for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);

        while(!q.empty()){
            for(int i:nodes[q.front()]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
            ans.push_back(q.front()); q.pop();
        }
        if(n==ans.size()) return ans;
        return {};
    }
};