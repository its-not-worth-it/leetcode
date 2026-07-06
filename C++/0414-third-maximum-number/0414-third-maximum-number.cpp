class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a=-1e10, b=-1e10, c=-1e10;
        for(int i:nums){
            if(a==(long long) -1e10) a=i;
            else if(b==(long long) -1e10){
                if((int)a==i) continue;
                else if((int)a<i) b=i;
                else {
                    b=a; a=i;
                }
            }else if(c==(long long)-1e10){
                if( (int)a==i or (int) b==i) continue;
                else if((int) a>i ){
                    c=b; b=a; a=i;
                }else if((int)b>i){
                    c=b; b=i;
                }else c=i;
            }else{
                if((int)a>=i or (int)b==i or (int) c==i) continue;
                else if( (int)c<i){
                    a=b; b=c; c=i;
                }else if( (int)b<i){
                    a=b; b=i;
                }else a=i;
            }
        }
        return c==(long long)-1e10? b==(long long)-1e10? a:b: a;
    }
};