class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size(), prev=0, ans=0;
        

        for(int i=0;i<m;i++){
            vector<int> v(n,0);
            for(int j=i;j<m;j++){
                for(int x=0;x<n;x++) v[x]+=matrix[x][j];
                unordered_map<int, int> m;
                m[0]=1;
                prev=0;
                for(int i:v){
                    prev+=i;
                    if(m.count(prev-target)) ans+=m[prev-target];
                    m[prev]++;
                }
            }
        }
        return ans;
    }
};