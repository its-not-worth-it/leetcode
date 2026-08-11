class Solution {
public:
    int countValidPrefixes(string s) {
        int zero=0, one=0;
        int ans=0;
        for(char i: s){
            if(i=='1') one++;
            else zero++;

            if( one==zero or abs(one-zero)==1 ) ans++;
        }
        return ans;
    }
};