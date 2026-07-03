class Solution {
public:
    vector<int> v{vector<int> (9,0)};
    Solution(){
        v[0]=1;
        v[1]=9;
        for(int i=2;i<9;i++){
            v[i]=v[i-1]*(9-i+2);
        }
        for(int i=1;i<9;i++) v[i]+=v[i-1];
    }
    int countNumbersWithUniqueDigits(int n) {
        return v[n];


    }
};