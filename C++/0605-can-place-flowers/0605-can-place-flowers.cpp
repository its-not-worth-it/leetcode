class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==1){
                if(i-1>=0 and flowerbed[i-1]==0) flowerbed[i-1]=-1;
                if(i+1 < flowerbed.size() and flowerbed[i+1]==0) flowerbed[i+1]=-1;
            }
        }
        int i=0, j, s;
        while(i<(int)flowerbed.size()){
            if(flowerbed[i]==0){
                j=i+1;
                while(j<flowerbed.size() and flowerbed[j]==0) j++;
                s=j-i;
                n-=((s/2)+(s&1));
                i=j+1;
            }
            else i++;
        }
        return n<=0? 1:0;
    }
};