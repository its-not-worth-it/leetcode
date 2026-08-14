class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0, j=0, n=s.size(), ans=1;
        vector<int> vis(26,0);
        while(j<n){
            vis[s[j]-'a']++;
            while(vis[s[j]-'a'] > 2){
                vis[s[i]-'a']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};