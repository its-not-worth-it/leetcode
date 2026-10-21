class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int left= ranges::count_if(nums, [&](int x){ return x< target;});
        int right= ranges::count_if(nums, [&](int x){ return x<= target;});
        vector<int> ans(right-left);
        iota(ans.begin(), ans.end(), left);
        return ans;
    }
};