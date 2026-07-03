class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vis(26,0);
        for(char i:p) vis[i-'a']++;
        
        vector<int> temp(26,0);
        vector<int> ans;

        int i=0,j=0;
        while(j<(int)s.size()){
            temp[s[j]-'a']++;
            j++;
            while(temp[s[j-1]-'a'] > vis[s[j-1]-'a']){
                temp[s[i]-'a']--; i++;
            }
            if(vis==temp){
                ans.push_back(i);
                temp[s[i]-'a']--;
                i++;
            }
        }
        return ans;
    }
};