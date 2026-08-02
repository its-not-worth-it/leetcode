class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        memset(memo,-1,sizeof(memo));
        // int n=piles.size();
        // vector<vector<int>> memo(n, vector<int>(n, -1));
        return help(piles,0,(int)piles.size()-1)>0;
        // return true;
    }
    int memo[501][501];
    int help(vector<int> &piles,int i, int j){
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        
        return memo[i][j] = max(piles[i] - help(piles, i + 1, j), piles[j] - help(piles, i, j - 1));
    }
};

