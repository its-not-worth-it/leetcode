class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int l=1, h=*max_element(nums.begin(),nums.end()), mid, temp, ans=INT_MAX;
        while(l<=h){
            mid=l+(h-l)/2;
            temp=0;
            for(int &i:nums){
                temp+=i/mid;
                if(i%mid) temp++;
            }
            if(temp<=t){
                ans=min(mid,ans);
                h=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};