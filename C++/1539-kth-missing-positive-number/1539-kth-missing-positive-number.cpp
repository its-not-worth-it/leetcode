class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0]) return k;
        int l=1, h=arr.size()-1, mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(arr[mid]-mid-1<k) {
                l=mid+1;
            }
            else h=mid-1;
        }
        return k+h+1;
    }
};