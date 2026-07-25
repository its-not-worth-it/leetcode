class Solution {
public:
    int maxProduct(int n) {
        int a=n%10;
        n/=10; int b=n%10; n/=10;
        if(a>b) swap(a,b);
        while(n){
            if(n%10 > b){
                a=b; b=n%10;
            }else if(n%10 >a){
                a=n%10;
            }
            n/=10;
        }
        return a*b;
    }
};