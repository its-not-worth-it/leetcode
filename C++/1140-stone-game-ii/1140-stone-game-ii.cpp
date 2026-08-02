class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> mp((int)piles.size(), vector<int>((int)piles.size()));
        vector<int> vis{piles};
        for(int i=(int)piles.size()-2; i>=0;i--){
            vis[i]+=vis[i+1];
        }
        return help(vis, mp, 1, 0);
    }
    int help(vector<int>& vis, vector<vector<int>> &mp, int m, int i){
        if(i+ 2*m >= (int)vis.size() ) return vis[i];
        if(mp[i][m] > 0) return mp[i][m];

        int res=INT_MAX;
        for(int k=1; k<= 2*m; k++){
            res=min(res, help(vis,mp, max(m,k), i+k) );
        }
        
        mp[i][m]=vis[i]-res;
        return mp[i][m];
    }
};