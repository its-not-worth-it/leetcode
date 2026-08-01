class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> v(nums.size(),vector<int>(nums.size(),INT_MIN));
        return help(nums, 0, nums.size()-1 ,v)>=0;
    }
    int help(vector<int>& nums, int i, int j,vector<vector<int>>& v){
        if(v[i][j]!=INT_MIN) return v[i][j];
        if(i==j) {
            return nums[i];
        }
        int l=nums[i]-help(nums,i+1,j,v);
        int r=nums[j]-help(nums, i, j-1,v);
        return v[i][j]=max(l,r);
    }
};