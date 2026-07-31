class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vis(26,0);
        for(char &i: word) vis[i-'a']++;
        sort(vis.rbegin(), vis.rend());
        int ans=0, n=1, t=1;
        for(int i: vis){
            if(i>=1){
                if(n%9==0){
                    n=1; t++;
                }
                ans+=(t*i); 
                n++;
                
            }
        }
        return ans;
    }
};