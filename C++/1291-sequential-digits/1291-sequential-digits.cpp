class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<10;i++){
            int temp=i;
            for(int j=i+1;j<10;j++){
                temp=temp*10+j;
                if(temp>=low and temp<=high) ans.push_back(temp);
                if(temp>high) break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};