class Solution {
public:
    int countGoodNumbers(long long n) {
        long long o=n/2, e=n/2;
        if(n&1) e++;
        long long i=1, ans=0,odd=4, even=5;
        long long temp_odd=1, temp_even=1;
        while(i<=e){
            if(e&i){
                temp_even=(temp_even * even) % (long long)(1e9+7);
            }
            i<<=1;
            even=(even * even) % (long long)(1e9+7);
        }
        i=1;
        while(i<=o){
            if(o&i){
                temp_odd=(temp_odd * odd) % (long long)(1e9+7);
            }
            i<<=1;
            odd=(odd * odd) % (long long)(1e9+7);
        }
        return (temp_even * temp_odd) % (int) (1e9+7);
    }
};