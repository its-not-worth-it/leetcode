class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j, n=nums.size();
        while(i < n){
            j=i+1;
            while(j<n and nums[j]==nums[i]){
                if(j-i >= 2) nums[j]=1e5;
                j++;
            }
            i=j;
        }
        i=0; j=0;
        while(j<n){
            if(nums[j] != (int) 1e5){
                swap(nums[j], nums[i]);
                i++;
            }
            j++;
        }
        return i;
    }
};