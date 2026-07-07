class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);

        int n=n1+n2, left=(n+1)/2;
        int l=0, h=n1, mid1, mid2;
        int l1, l2, h1, h2, x, y;
        while(l<=h){
            mid1=l+(h-l)/2;
            mid2=left-mid1;

            h1=INT_MAX; h2=INT_MAX; l1=INT_MIN; l2=INT_MIN;
            if(mid1<n1) h1=nums1[mid1];
            if(mid2<n2) h2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            x=max(l1,l2); y=min(h1,h2);
            if(x<=y){
                if(n&1) return x;
                return (double)(x+y)/2LL;
            }else {
                if(l1>l2) h=mid1-1;
                else l=mid1+1;
            }

        }
        return 0;
    }
};