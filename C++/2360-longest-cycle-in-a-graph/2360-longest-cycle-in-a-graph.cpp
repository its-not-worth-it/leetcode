class Solution {
public:
    int ans;
    int longestCycle(vector<int>& edges) {
        int n=edges.size(), cnt, cy=0;
        vector<int> cy_map(n,-1);
        vector<int> vis(n,-1);
        ans=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                cnt=0;
                cy++;
                help(cy_map, vis, edges, cy, cnt, i);
            }
        }
        return ans;

    }
    void help(vector<int> &cy_map, vector<int> &vis, vector<int> &edges, int &cy, int &cnt, int i){
        if(cy_map[i] != -1) {
            if(cy_map[i]==cy) ans=max(ans, cnt-vis[i]);
            return;
        }
        vis[i]=cnt;
        ++cnt;
        cy_map[i]=cy;
        if(edges[i]==-1 ) return;
        help(cy_map, vis, edges, cy, cnt, edges[i]);
    }
};