class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> greater, lesser; 
        int ans=0, j=0;;

        for(int i=0;i<(int)nums.size();i++){
            
            while(!greater.empty() and nums[greater.back()]<nums[i]) greater.pop_back();
            while(!lesser.empty() and nums[lesser.back()]>nums[i]) lesser.pop_back();
            greater.push_back(i);
            lesser.push_back(i);

            while(!greater.empty() and !lesser.empty() and nums[greater.front()]-nums[lesser.front()] > limit){
                if(j==greater.front()) greater.pop_front();
                if(j==lesser.front()) lesser.pop_front();
                j++;
            }
            ans=max(ans,i-j+1);

        }
        return ans;
    }
};