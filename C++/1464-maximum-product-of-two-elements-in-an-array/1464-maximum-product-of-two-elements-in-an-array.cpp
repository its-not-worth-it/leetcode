class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a=max(nums[0], nums[1]), b=min(nums[0], nums[1]);
        for(int i=2;i<(int)nums.size();i++){
            if(nums[i]>a){
                b=a; a=nums[i];
            }else if(nums[i]>b){
                b=nums[i];
            }
        }
        return (a-1) * (b-1);
    }
};