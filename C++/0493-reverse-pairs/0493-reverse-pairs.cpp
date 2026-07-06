class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        help(nums, ans, 0,n-1);
        return ans;
    }
    void help(vector<int>& nums, int &ans, int l, int h){
        if(l<h){
            int mid=l+(h-l)/2;

            help(nums, ans, l, mid);
            help(nums, ans, mid+1, h);

            merge(nums, ans, l, mid, h);
        }
    }
    void merge(vector<int>& nums, int& ans, int &l, int &mid, int &h){
        int n=mid-l+1, m=h-mid;
        vector<int> s(n), t(m);
        for(int i=0;i<n;i++) s[i]=nums[l+i];
        for(int i=0;i<m;i++) t[i]=nums[mid+1+i];

        int i=0, j=0, k=l;
        while(i<n and j<m){
            if((long long)s[i]>2LL* t[j]){
                ans+=m-j;
                i++;
            }else j++;
        }
        j=0; i=0;
        while(i<n and j<m){
            if(s[i]> t[j]){
                nums[k]=s[i];
                i++;
            }else{
                nums[k]=t[j];
                j++;
            }
            k++;
        }
        while(i<n){
            nums[k]=s[i]; i++; k++;
        }
        while(j<m){
            nums[k]=t[j]; j++; k++;
        }
    }
};