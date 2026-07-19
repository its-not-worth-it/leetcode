class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> vis(26,0), v(26,0);
        for(char i:s) {
            vis[i-'a']++;
            if(vis[i-'a']==1) v[i-'a']=1;
        }
        string ans; ans.reserve((int)s.size());
        for(char i:s){
            if(!v[i-'a']){
                vis[i-'a']--; 
                continue;
            }
            while(!ans.empty() and ans.back()>=i and vis[ans.back()-'a']>0){
                v[ans.back()-'a']=1;
                ans.pop_back();
            }
            vis[i-'a']--; 
            ans.push_back(i);
            // cout<<ans<<endl;
            v[i-'a']=0;
        }

        return ans;
    }
};