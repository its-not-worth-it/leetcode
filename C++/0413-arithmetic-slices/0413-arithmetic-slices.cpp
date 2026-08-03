class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if((int)nums.size() < 3) return 0;
        int ans=0, t=0, prev=nums[1]-nums[0], pres;

        for(int i=1;i<(int)nums.size()-1;i++){
            pres=nums[i+1]-nums[i];

            if(prev==pres){
                t++;
            }else{
                prev=pres;
                t=0;
            }
            ans+=t;
        }

        return ans;

    }
};