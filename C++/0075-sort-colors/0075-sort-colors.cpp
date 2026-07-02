class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=(int)nums.size()-1;
        while(j<=k){
            if(nums[j]==0 and i==j){
                j++;i++;
            }else if(nums[j]==2){
                swap(nums[k],nums[j]);k--;
            }
            else if(nums[j]==0){
                swap(nums[i],nums[j]);j++;i++;
            }else j++;
        }
    }
};