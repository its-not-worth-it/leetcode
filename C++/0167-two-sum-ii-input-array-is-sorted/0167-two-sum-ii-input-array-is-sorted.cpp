class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<numbers.size();i++){
            if(m.count(target-numbers[i])) return {m[target-numbers[i]],i+1};
            m[numbers[i]]=i+1;
        }
        return {};
    }
};