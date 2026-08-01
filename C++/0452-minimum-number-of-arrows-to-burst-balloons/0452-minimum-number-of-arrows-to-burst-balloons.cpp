class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans=1, a=points[0][0], b=points[0][1];
        for(int i=1;i<(int)points.size();i++){
            if(b >= points[i][0]){
                a=max(points[i][0], a);
                b=min(points[i][1],b);
            }else {
                a=points[i][0];
                b=points[i][1];
                ans++;
            }
        }
        return ans;
    }
};