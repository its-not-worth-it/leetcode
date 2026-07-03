class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i:nums) s.emplace(i);
        int t,l=0,m=0;
        for(auto i=s.begin();i!=s.end(); i++){
            t=*i;
            if(s.count(t-1)) continue;
            m=1;
            while(s.count(t+1)){
                m++;
                t++;
            }
            l=max(m,l);
        }

        return l;

    }
};