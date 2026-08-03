class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> temp(n,1e9);
        int ans=help(stoneValue, temp, 0);
        cout<<ans;
        if(ans > 0){
            return "Alice";
        }else if(ans < 0) {
            return "Bob";
        }
        return "Tie";
    }
    int help(vector<int> &stoneValue, vector<int> &temp, int i){
        if(i >= temp.size()) return 0;
        if(temp[i] != (int) 1e9) return temp[i];

        int res=INT_MIN, x=0;

        for(int k=1;k<=3; k++){
            if(i+k <= (int) temp.size()) x+=stoneValue[i+k-1];
            else break;
            res=max(res, x-help(stoneValue,temp, i+k));
        }
        return temp[i]= res;
    }
};