class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int n=mat.size(), m=mat[0].size(),t,x,y,z;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            t=q.size();
            while(t--){
                x=q.front().first; y=q.front().second; z=mat[x][y];
                q.pop();
                
                if(x>0 and !vis[x-1][y]){
                    vis[x-1][y]=true; mat[x-1][y]=z+1;
                    q.push({x-1,y});
                }
                if(x<n-1 and !vis[x+1][y]){
                    vis[x+1][y]=true; mat[x+1][y]=z+1;
                    q.push({x+1,y});
                }
                if(y>0 and !vis[x][y-1]){
                    vis[x][y-1]=true; mat[x][y-1]=z+1;
                    q.push({x,y-1});
                }
                if(y<m-1 and !vis[x][y+1]){
                    vis[x][y+1]=true; mat[x][y+1]=z+1;
                    q.push({x,y+1});
                }
            }
        }
        return mat;
    }
};