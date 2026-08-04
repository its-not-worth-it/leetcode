class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int> c, r;
        for(int &i: planks){
            c[i]++; r[i]++;
        }
        for(auto i: c){
            for(auto j: c){
                int a=i.first, b=j.first;
                if(a<b) r[a+b]+=min(c[a], c[b]);
                else if(a==b) r[a+b]+=c[a]/2;
            }
        }
        int ans=0;
        for( auto [j,k]: r){
            ans=max(ans, k);
        }

        return ans;
        
    }
};