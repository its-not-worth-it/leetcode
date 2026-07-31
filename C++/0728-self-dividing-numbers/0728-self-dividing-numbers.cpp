class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        int x; bool f;
        for(int i=left; i<=right; i++){ 
            f=true;
            x=i;
            while(x){
                if(x%10==0 or (i% (x%10))) {
                    f=false ;
                    break;
                }
                x/=10;
            }
            if(f) ans.push_back(i);
        }
        return ans;
    }
};