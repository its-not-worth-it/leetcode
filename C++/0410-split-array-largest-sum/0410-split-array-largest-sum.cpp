class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0, h=accumulate(nums.begin(), nums.end(), 0), mid, t, temp, ans=INT_MAX;
        bool f;
        while(l<=h){
            mid=l+(h-l)/2;
            temp=0; t=0;
            f=false;
            for(int &i:nums){
                if(i>mid) {
                    f=true;
                    break;
                }
                if(temp+i>mid){
                    t++; temp=i;
                }else temp+=i;
            }
            if(f){
                l=mid+1;
                continue;
            }
            t++;
            if(t<=k){
                ans=min(ans,mid);
                h=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};