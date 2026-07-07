class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0, h=arr.size()-1,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(l==mid){
                return arr[mid]<arr[h]? h:l;
            }else if(arr[mid]<arr[mid+1]) l=mid+1;
            else h=mid;
        }
        return l;
    }
};