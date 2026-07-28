class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int x=-1, m=-1; 
        unordered_map<int,int> mp;
        for(int &i : nums) mp[i]++;

        for(auto [j,k]: mp){
            if(! (j&1)){
                if(m < k){
                    m=k; x=j;
                }else if(m==k){
                    x=min(x,j);
                }
            }
        }
        return x;
    }
};