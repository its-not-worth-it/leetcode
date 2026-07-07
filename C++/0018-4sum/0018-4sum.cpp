class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j,k,l; long long sum;
        vector<vector<int>> ans;
        for(int i=0;i<(int)nums.size();i++){
            if(i-1>=0 and nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<(int)nums.size();j++){
                if(j-1!=i and nums[j]==nums[j-1]) continue;
                
                sum=nums[i]+nums[j]; 
                k=j+1; l=nums.size()-1;

                while(k<l){
                    // cout<<i<<" "<<j<<" "<<k<< " "<<l<<endl;
                    sum=nums[i]+nums[j];
                    sum+=nums[k]+nums[l];

                    if(sum==(long long)target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while(k<(int)nums.size() and nums[k]==nums[k-1]) k++;
                    }
                    else if(sum<target) k++; 
                    else l--;    
                }
            }
        }
        return ans;
    }
};