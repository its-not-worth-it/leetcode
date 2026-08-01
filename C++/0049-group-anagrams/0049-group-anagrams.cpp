class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        string s;
        for(string i: strs){
            s=i;
            sort(i.begin(),i.end());
            mp[i].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto [j,k]: mp) ans.push_back(k);
        return ans;
    }
};