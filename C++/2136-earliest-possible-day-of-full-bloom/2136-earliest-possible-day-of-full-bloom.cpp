class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n=p.size();
        struct comp{
            bool operator()(const pair<int,int> &a, const pair<int,int> &b){
                if(a.second==b.second) return a.first > b.first;
                return a.second < b.second;
            }

        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp > pq;
        for(int i=0;i<n;i++){
            pq.push({p[i], g[i]});
        }
        int ans=0, tmax=0, pmax=0;
        pmax=pq.top().first-1; tmax=pmax+pq.top().second+1; pq.pop();
        ans=tmax;
        while(!pq.empty()){
            pmax+=pq.top().first;
            tmax=pmax+pq.top().second+1;
            ans=max(ans, tmax);
            pq.pop();
        }

        return ans;
        
    }
};