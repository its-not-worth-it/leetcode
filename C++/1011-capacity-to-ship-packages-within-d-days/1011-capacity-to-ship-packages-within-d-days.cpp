class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(), weights.end()), h=accumulate(weights.begin(),weights.end(),0), mid, d, temp, ans=INT_MAX;
        while(l<=h){
            mid=l+(h-l)/2;
            d=0; temp=0;
            for(int &i:weights){
                if(temp+i>mid){
                    d++;
                    temp=i;
                }else temp+=i;
            }
            d++;
            // cout<<mid<<" "<<d<<endl;
            if(d<=days){
                ans=min(ans, mid);
                h=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};