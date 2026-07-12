class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s="balloon";
        int ans=INT_MAX;
        vector<int> v(26,0), vis(26,0);
        for(char i:text) vis[i-'a']++;
        for( char i:s) v[i-'a']++;
        for(int i=0;i<26;i++){
            if(v[i]){
                ans=min(ans,vis[i]/v[i]);
            }
        }
        return ans;
    }
};