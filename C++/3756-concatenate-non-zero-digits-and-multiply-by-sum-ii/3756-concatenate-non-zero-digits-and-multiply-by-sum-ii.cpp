class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        long long m=1e9+7;
        vector<long long> pre(n+1,0), sum(n+1,0), pow10(n+1,1); vector<int> nos(n+1,0);
        for(int i=1;i<=n;i++) pow10[i]= (pow10[i-1]*10) % m; 
        
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'){
                c++;
                pre[c]=(pre[c-1]*10+ (s[i]-'0')) % m;
                sum[c]=sum[c-1]+ (s[i]-'0');
            }
            nos[i+1]=c;
        }
        vector<int> ans((int)queries.size(),0);
        int l,r,rem,i=0;
        for(auto& q: queries){
            l=nos[q[0]]; r=nos[q[1]+1];
            if(l==r) {i++; continue;}
            rem= (pre[r] -(pre[l]*pow10[r-l]) ) % m;
            if(rem<0) rem+=m;
            ans[i]= (rem * (sum[r]-sum[l])) % m;
            i++;
        }
        return ans;
    }
};