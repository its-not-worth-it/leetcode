class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> vis(26,0);
        for( char &i: s) vis[i-'a']++;
        string ans="";  int x=-1, y; ans.reserve((int)s.size());
        for(int i=0;i<26;i++){
            y=vis[i];
            if(y&1) x=i;
            y>>=1;
            while(y){
                ans.push_back(97+i);
                y--;
            }
        }
        y=ans.size()-1;
        if(x!=-1) ans.push_back(97+x);
        while(y>=0){
            ans.push_back(ans[y]);
            y--;
        }
        return ans;
    }
};