class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> v(2*10001,0);
        for(int i:nums) v[i+10000]++;
        for(int i=20001;i>=0;i--){
            if(v[i] and k<=v[i]) return i-10000;
            else k-=v[i];
        }
        return 0;
    }
};