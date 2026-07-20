class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans; ans.reserve(k);
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > p;
        for(int i:nums1){
            p.push({i+nums2[0],0});
        }
        int x,y;
        while(k-- ){
            x=p.top().first; y=p.top().second;
            p.pop();
            if(k and y<nums2.size()-1){
                p.push({x-nums2[y]+nums2[y+1],y+1});
            }
            ans.push_back({x-nums2[y],nums2[y]});
        }
        return ans;
    }
};