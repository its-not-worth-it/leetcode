class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long mid, l=-1e11, r=1e11, ans=-1e11, x;
        while(l<=r){
            mid=l+(r-l)/2;
            x=cal(nums1, nums2, mid);
            if(x>=k){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
    long long cal(vector<int> &nums1, vector<int> &nums2, long long &t){
        long long ans=0;
        int l=0, n=nums2.size(), h, mid, pos; 
        for(int i:nums1){
            if(i==0){
                if(t>=0) ans+=n;
            }else{
                l=0; h=n-1;
                if(i<0){
                    pos=n;
                    while(l<=h){
                        mid=l+(h-l)/2;
                        if((long long )i * nums2[mid]<= t){
                            pos=mid; 
                            h=mid-1;
                        }else l=mid+1;
                    }
                    ans+=n-pos;
                }else{
                    pos=-1;
                    while(l<=h){
                        mid=l+(h-l)/2;
                        if((long long )i * nums2[mid]<= t){
                            pos=mid; 
                            l=mid+1;
                        }else h=mid-1;
                    }
                    ans+=pos+1;
                }
            }
            
        }
        return ans;
    }
};