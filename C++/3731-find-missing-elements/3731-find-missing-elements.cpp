class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int i=0, l=nums[0], h=nums[(int)nums.size()-1];
        while(l<=h){
            if(l==nums[i]){
                i++;
            }else{
                ans.push_back(l);
            }
            l++;
        }
        return ans;
    }
};