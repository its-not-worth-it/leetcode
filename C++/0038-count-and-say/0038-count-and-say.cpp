class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1; i<n; i++){
            ans=help(ans);
        }

        return ans;
    }
    string help(string ans){
        vector<pair<int,int>> temp;
        int i=0, j;
        while(i<(int)ans.size()){
            j=i+1;
            while(j<(int)ans.size() and ans[j]==ans[i]) j++;
            temp.push_back({j-i,ans[i]-'0'});
            i=j;
        }
        string s=""; s.reserve((int)temp.size() * 2);
        for(auto [k,l]: temp){
            s.push_back('0'+k);
            s.push_back('0'+l);
        }
        return s;
    }
};