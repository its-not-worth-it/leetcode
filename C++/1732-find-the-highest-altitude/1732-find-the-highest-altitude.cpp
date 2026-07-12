class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,temp=0;
        for(int &i:gain){
            temp+=i;
            ans=max(ans,temp);
        }
        return ans;
    }
};