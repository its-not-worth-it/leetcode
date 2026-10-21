class Solution {
public:
    int minOperations(string s) {
        if(1==s.size()) return 0;
        else if(2==s.size()){
            if(s[0]>s[1]) return -1;
            return 0;
        }
        char small=s[0], big=s[0];
        int idx_s=0, idx_b=0, n=s.size();
        bool f=true;
        
        for(int i=1;i<n;i++){
            if(s[i]< small) {
                small=s[i]; idx_s=i;
            }
            if(s[i] >= big){
                big=s[i]; idx_b=i;
            }
            if(f and s[i] < s[i-1]) f=false;
        }
        if(f) return 0;
        else if(idx_s==n-1 and idx_b==0) return 3;
        else if(idx_s==0 or idx_b==n-1) return 1;
        return 2;

        
        
    }
};