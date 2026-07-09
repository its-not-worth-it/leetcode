class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(), ans=INT_MIN, temp=1,t=1;
        for(int i=0;i<n;i++){
            temp*=nums[i];
            t*=nums[n-i-1];
            ans=max(ans,max(temp,t));
            if(temp==0) temp=1;
            if(t==0) t=1;
        }
        
        return ans;
    }
};