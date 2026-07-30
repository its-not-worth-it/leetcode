class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int t=n/8, s=n%8;
        return t*(t+1)*4 +(t+1)*s; 
    }
};