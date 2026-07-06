class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long pre=0;
        int n=nums.size();
        vector<long long> sums(n+1,0);
        for(int i=0;i<n;i++) sums[i+1]=sums[i]+nums[i];

        return help(sums, lower, upper, 0, n);
    }
    int help(vector<long long>& sums, int lower, int upper, int l, int h){
        if(l>=h) return 0;

        int mid=l+(h-l)/2;
        int count= help(sums, lower, upper, l, mid) + help(sums, lower, upper, mid+1, h);

        int lb=mid+1, hb=mid+1;
        for(int i=l;i<=mid; i++){
            while(lb<=h and sums[lb]-sums[i]<lower) lb++;
            while(hb<=h and sums[hb]-sums[i]<=upper) hb++;
            count+=hb-lb;
        }

        inplace_merge(sums.begin()+l, sums.begin()+mid+1, sums.begin()+h+1);
        return count;
        
    }
};