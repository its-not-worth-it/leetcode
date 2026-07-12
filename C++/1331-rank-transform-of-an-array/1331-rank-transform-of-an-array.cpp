class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> m;
        for(int i:arr) m[i]=0;
        int temp=0;
        for(auto [j,k]:m){
            temp++;
            m[j]=temp;
        }
        for(int &i:arr){
            i=m[i];
        }
        return arr;
    }
};