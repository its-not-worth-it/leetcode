class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;    vector<int> temp; temp.reserve((int)graph.size());
        help(ans,temp,0,graph);
        return ans;
    }
    void help(vector<vector<int>> &ans, vector<int> &temp, int i,vector<vector<int>>& graph){
        temp.emplace_back(i);
        if(i==(int)graph.size()-1){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int j: graph[i]){
            help(ans,temp,j,graph);
        }
        temp.pop_back();
    }
};