class Solution {
public:
    int kthGrammar(int n, int k) {
        bool f=true;
        n=pow(2,n-1);
        while(n>1){
            n>>=1;
            
            if(k>n){
                k-=n;
                f=!f;
            }
        }
        return (f)? 0:1;
    }
};