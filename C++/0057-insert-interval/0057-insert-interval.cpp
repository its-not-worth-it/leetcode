class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& nit) {
        vector<vector<int>> ans;
        int i=0, n=intervals.size();
        for(;i<n;i++){
            if(intervals[i][0] > nit[0]) break;
            ans.push_back(intervals[i]);
        }

        if(ans.empty() or ( ans.back()[1]< nit[0]) ) ans.push_back(nit);
        else ans.back()[1]=max(ans.back()[1], nit[1]);

        while(i<n){
            if(ans.back()[1] >= intervals[i][0]) ans.back()[1]=max(ans.back()[1], intervals[i][1]);
            else ans.push_back(intervals[i]);
            i++;
        }



        return ans;
    }
};