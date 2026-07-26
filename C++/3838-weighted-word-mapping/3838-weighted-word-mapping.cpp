class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";  int x;
        for(string &i:words){
            x=0;
            for(char &j: i){
                x+=weights[j-'a'];
            }
            x%=26;
            ans.push_back(122-x);
        }
        return ans;
    }
};