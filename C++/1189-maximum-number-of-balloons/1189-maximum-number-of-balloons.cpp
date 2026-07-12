class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> vis(26,0);
        for(char i: text) vis[i-'a']++;
        return min({
            vis['b'-'a'], vis['a'-'a'], vis['l'-'a']/2, vis['n'-'a'], vis['o'-'a']/2
        });
    }
};