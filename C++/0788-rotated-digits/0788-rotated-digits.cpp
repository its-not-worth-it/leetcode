class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(help(i)) ans++;
        }
        return ans;
    }
    bool help(int a){
        bool f=false;
        int d;
        while(a){
            d=a%10;
            if(d==4 or d==7 or d==3) return false;
            else if(d==2 or d==9 or d==6 or d==5) f=true;
            a/=10;
        }
        return f;
    }
};