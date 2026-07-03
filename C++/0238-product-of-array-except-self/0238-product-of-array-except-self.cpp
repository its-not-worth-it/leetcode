class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre((int)nums.size(),0);
        pre[0]=1;
        for(int i=1;i<(int)nums.size();i++){
            pre[i]=pre[i-1]*nums[i-1];
            // cout<<pre[i]<<" ";
        }
        int a=1;
        for(int i=(int)nums.size()-1;i>0;i--){
            pre[i]*=a;
            a*=nums[i];
        }
        pre[0]=a;
        return pre;
    }
};