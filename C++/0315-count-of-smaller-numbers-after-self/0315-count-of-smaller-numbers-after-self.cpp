class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> m(n);
        for(int i=0;i<n;i++) m[i]={nums[i],i};

        help(m, ans, 0, n-1);

        return ans;
    }
    void help(vector<pair<int,int>> &m, vector<int> &ans, int l, int r){
        if(l<r){
            int mid=l+(r-l)/2;

            help(m, ans, l, mid );
            help(m, ans, mid+1, r );

            merge(m, ans, l, mid, r);
        }
    }

    void merge(vector<pair<int,int>> &t, vector<int> &ans, int l, int mid, int r){
        int n= mid-l+1, m=r-mid;
        vector<pair<int,int>> v1(n), v2(m);
        for(int i=0;i<n;i++) v1[i]=t[l+i];
        for(int i=0;i<m;i++) v2[i]=t[mid+1+i];

        int i=0, j=0, k=l;
        while(i<n and j<m){
            if(v1[i].first > v2[j].first) {
                ans[v1[i].second]+=m-j;
                t[k]=v1[i];
                i++;
            }else{
                t[k]=v2[j]; j++;
            }
            k++;
        }
        while(j<m){
            t[k]=v2[j]; j++; k++;
        }
        while(i<n){
            t[k]=v1[i];
            i++;    k++;
        }
    }
};