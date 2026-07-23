class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(), ans=0, index=0, m=0;
        for(int i=0;i<n;i++){
            gas[i]-=cost[i];
            cout<<gas[i]<<" ";
            ans+=gas[i];
            m+=gas[i];
            if(m<0){
                m=0; index=i+1;
            }
        }
        if(ans<0) return -1;
        return index;
    }
};