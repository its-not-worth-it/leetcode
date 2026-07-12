class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans=INT_MIN, n=matrix.size(), m=matrix[0].size();
        int prev=0;
        set<int>::iterator it;
        for(int i=0;i<m;i++){
            vector<int> v(n,0);
            for(int j=i;j<m;j++){
                for(int x=0;x<n;x++) v[x]+=matrix[x][j];
                set<int> s; s.insert(0);
                prev=0;
                for(int i:v){
                    prev+=i;
                    it=s.lower_bound(prev-k);
                    if(it !=s.end()){
                        ans=max(ans,prev-*it);
                    }
                    s.insert(prev);
                }
            }
        }
        return ans;
        
    }
};