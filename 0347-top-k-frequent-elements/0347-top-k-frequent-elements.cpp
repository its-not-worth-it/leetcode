class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int t) {
        unordered_map<int,int> m;
        for(int i:nums) m[i]++;
        vector<vector<int>> v((int)nums.size()+1);
        for(auto [k,l]:m){
            v[l].push_back(k);
        }
        vector<int> ans;
        int i=nums.size();
        while(i>=0){
            for(int x:v[i]){
                ans.push_back(x); t--;
                if(!t) return ans;
            }
            i--;
        }
        return {};
    }
};