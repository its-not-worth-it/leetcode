class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        int x=n; n=0; int sum=0;
        while(x){
            if(x%10) n=n*10+x%10; 
            x/=10;
        }
        while(n){
            ans=ans*10+n%10;
            sum+=n%10;
            n/=10;
        }
        return ans*sum;
    }
};