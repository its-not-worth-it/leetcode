class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        
        bool f= (dividend<0) == (divisor<0);
        unsigned int a=dividend<0? (unsigned int)dividend * -1: (unsigned int)dividend;
        unsigned int b=divisor<0? (unsigned int)divisor * -1: (unsigned int)divisor;
        unsigned int ans=0;
        short q;
        while(a>=b){
            q=0;
            while(a > (b<<(q+1)) ){
                q++;
            }
            ans+= (1<<q);
            a-=(b<<q);
        }
        if(ans== (1<<31) and f) return INT_MAX;
        
        return f? ans: -ans;
    }
};