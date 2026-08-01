class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int &i: arr) m[i]++;
        unordered_set<int> s;
        for(auto [j,k]: m){
            if(s.contains(k)) return 0;
            s.insert(k);
        }
        return 1;
    }
};