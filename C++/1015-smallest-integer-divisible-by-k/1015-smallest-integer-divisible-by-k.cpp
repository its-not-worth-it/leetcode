class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int t=1,ans=1;
        unordered_set<int> m;
        m.insert(1);
        // if(t%k==0) return 1;
        while(t%k !=0){
            t=t*10+1;
            t=t%k;
            if(m.count(t)) return -1;
            m.insert(t);
            ans++;
        }
        return ans;
    }
};