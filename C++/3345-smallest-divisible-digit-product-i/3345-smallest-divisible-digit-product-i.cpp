class Solution {
public:
    int smallestNumber(int n, int t) {
        int a, temp;
        while(n){
            a=n;
            temp=1;
            while(a){
                temp*=a%10;
                a/=10;
            }
            if(temp % t ==0) return n;
            n++;
        }
        return -1;
    }
};