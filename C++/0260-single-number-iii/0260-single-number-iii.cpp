class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int e=0; 
        for( int &i: nums) e^=i;

        int first=0, second=0, b=0;
        while(!(e>>b &1)) b++;

        for(int &i: nums){
            if(!(i>>b &1)) first^=i;
            else second^=i;
        }

        return {first,second};
    }
};