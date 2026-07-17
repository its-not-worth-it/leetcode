class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d; vector<int> ans; ans.reserve(k+1);
        for(int i=0;i<k;i++){
            while(!d.empty() and nums[d.front()]<nums[i]) d.pop_front();
            while(!d.empty() and nums[d.back()]<nums[i]) d.pop_back();
            d.push_back(i);
        }
        ans.push_back(nums[d.front()]);

        for(int i=k;i<(int)nums.size();i++){
            if(i-k==d.front()) d.pop_front();
            while(!d.empty() and nums[d.front()]<nums[i]) d.pop_front();
            while(!d.empty() and nums[d.back()]<nums[i]) d.pop_back();
            d.push_back(i);
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};