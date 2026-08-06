class Solution {
public:
    int smallestNumber(int n, int t) {
        auto [a,b]=div(n,10);

        int req=t/ gcd( max(1,a), t);
        int nxt;
        if(b % req==0) nxt=b;
        else nxt= (b/req +1 ) * req;

        if(nxt < 10) return a*10 + nxt;
        return (a+1) * 10;
    }
};