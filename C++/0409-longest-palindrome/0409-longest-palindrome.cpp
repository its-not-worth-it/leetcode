class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> vis(52,0);
        for(char i:s) {
            if(i-'A'>26){
                vis[i-'A'-6]++;
            }else vis[i-'A']++;
        }
        int ans=0; bool f=false;
        for(int i:vis){
            if(i&1){
                f=true;
                ans+=i-1;
            }else{
                ans+=i;
            }
        }
        return f?ans+1:ans;
    }
};