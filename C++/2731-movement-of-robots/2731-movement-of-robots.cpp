class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n=nums.size(), mod=1e9+7;
        for(int &i:nums) i=i%mod;
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                nums[i]-=d;
            }else nums[i]+=d;
        }
        sort(nums.begin(),nums.end());

        long long ans=0,temp, pre=0;
        for(int i=0;i<n;i++){
            temp=(nums[i]%mod+mod)%mod;
            ans+=(temp*i)%mod-pre;
            ans=ans%mod;
            pre=(pre+temp)%mod;
        }
        return (ans+mod)%mod;
    }
};