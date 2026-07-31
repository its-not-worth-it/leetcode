class Solution {
public:
    bool isUgly(int n) {
        while(n >= 5 and n%5==0) n/=5;
        while(n >=3 and n%3==0) n/=3;
        while(n >=2 and n%2==0) n/=2;

        return n==1? 1:0;
    }
};