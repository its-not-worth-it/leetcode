class Solution {
public:
    vector<vector<string>> findLadders(string b, string e, vector<string>& w) {
        unordered_set<string> s(w.begin(),w.end());
        if(!s.contains(e)) return {};

        s.erase(b);
        queue<string> q; q.push(b);
        unordered_map<string, vector<string>> temp;
        int n, m=b.size();  string x;

        while(!q.empty()){
            n=q.size(); unordered_set<string> vis;
            while(n--){
                for(int i=0;i<m;i++){
                    x=q.front();
                    for(int j=97;j<=122;j++){
                        x[i]=j;
                        if(x!=q.front() and s.contains(x)){
                            temp[x].push_back(q.front());
                            if(!vis.contains(x)){
                                vis.emplace(x);
                                q.push(x);
                            }
                        }
                    }
                }
                q.pop();
            }
            for(string i:vis) {
                s.erase(i);
            }
            if(temp.count(e)) break;
        }

        vector<vector<string>> ans; vector<string> vis;
        help(ans, vis, temp, e, b);
        for(vector<string> &i: ans) reverse(i.begin(),i.end());

        return ans;
    }
    void help(vector<vector<string>> &ans, vector<string> &vis, unordered_map<string, vector<string>> &temp, string a, string &b){
        vis.push_back(a);
        if(a==b){
            ans.push_back(vis);
            vis.pop_back();
            return;
        }
        for(string i: temp[a]) help(ans, vis, temp, i, b);

        vis.pop_back();
    }
};