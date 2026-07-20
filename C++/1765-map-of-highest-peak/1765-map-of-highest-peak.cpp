class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int n=w.size(), m=w[0].size(), t,x,y,z, l,h;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(w[i][j]==1) {w[i][j]=0; q.push({i,j});}
                else w[i][j]=-1;
            }
        }
        vector<int> vt{-1,1,0,0}, hz{0,0,-1,1};

        while(!q.empty()){
           
            x=q.front().first; y=q.front().second; z=w[x][y];
            q.pop();
            for(int i=0;i<4;i++){
                l=x+vt[i]; h=y+hz[i];
                if(l>=0 and l<n and h>=0 and h<m and w[l][h]==-1) {
                    w[l][h]=z+1;
                    q.push({l,h});
                }
            }
            
        }

        return w;
    }
};