class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto compare=[](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        };
        sort(intervals.begin(),intervals.end(), compare);

        // for(vector<int>& i:intervals){
        //     for(int j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        int i=0, j=0, ans=0;
        while(j<(int)intervals.size()){
            if(i==j) j++;
            while(j<(int)intervals.size() and intervals[i][0]<=intervals[j][0] and intervals[i][1]>= intervals[j][1]) j++;
            ans++;
            i=j;
        }

        return ans;
    }
};