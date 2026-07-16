class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size(), pre=0;
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            pre=max(pre, nums[i]);
            vis[i]=gcd(pre, nums[i]);
        }
        sort(vis.begin(), vis.end());
        int i=0, j=n-1; long long sum=0;
        while(i<j){
            sum+=gcd(vis[i], vis[j]);
            i++; j--;
        }
        return sum;
    }
    int gcd(int a, int b) {
        if (!a || !b)
            return a | b;
        unsigned shift = __builtin_ctz(a | b);
        a >>= __builtin_ctz(a);
        do {
            b >>= __builtin_ctz(b);
            if (a > b)
                swap(a, b);
            b -= a;
        } while (b);

        return a << shift;
    }
};