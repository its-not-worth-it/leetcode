class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        if((long long)m*k > (long long)b.size() ) return -1;
        int l=1, h=*max_element(b.begin(),b.end()), mid, t , ans=-1;
        while(l<=h){
            mid=l+(h-l)/2;
            t=0;
            for(int i=0;i<(int)b.size();i++){
                int j=i;
                while(j<(int)b.size() and b[j]<=mid) {
                    j++;
                }
                if(j-i>=k){ 
                    t+=(j-i)/k;
                }
                i=j;
            }

            if(t>= m){
                ans=mid; 
                h=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};