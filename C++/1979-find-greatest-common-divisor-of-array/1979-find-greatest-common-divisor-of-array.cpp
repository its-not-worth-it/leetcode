class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a=10001, b=-1;;
        for(int &i:nums){
            if(i>b) b=i;
            if(i<a) a=i;
        }
        return gcd(a,b);
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