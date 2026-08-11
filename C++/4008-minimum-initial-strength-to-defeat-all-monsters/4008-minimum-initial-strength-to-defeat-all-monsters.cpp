class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        vector<long long> bonus(n+1,0);
        for(auto i: boosts){
            bonus[i[0]]+=i[2];
            bonus[i[1]+1]-=i[2];
        }
        // for(auto i: bonus) cout<<i<<" ";
        // cout<<bonus[0]<<" ";
        for(int i=1;i<n+1;i++){
            bonus[i]=bonus[i-1]+bonus[i];
            // cout<<bonus[i]<<" ";
        }
        int i=n-1;
        for(;i>=0;i--){
            if(monsters[i] <= bonus[i]) monsters[i]=0;
            else {
                monsters[i]-=bonus[i];
                break;
            }
        }
        
        long long ans=accumulate(monsters.begin(),monsters.begin()+i+1,0LL);
        return ans;
    }
};