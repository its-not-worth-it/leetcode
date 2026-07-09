class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, h=height.size()-1, lmax=0, hmax=0, ans=0;
        while(l<h){
            if(height[l]<height[h]){
                if(height[l]>=lmax){
                    lmax=height[l];
                }else{
                    ans+=lmax-height[l];
                }
                l++;
            }else{
                if(height[h]>=hmax){
                    hmax=height[h];
                }else{
                    ans+=hmax-height[h];
                }
                h--;
            }
        }
        return ans;
    }
};