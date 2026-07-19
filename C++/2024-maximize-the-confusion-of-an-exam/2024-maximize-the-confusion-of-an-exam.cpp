class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int ans=0, i=0, j=0, n=a.size(), x=k;
        while(j<n){
            if(a[j]=='T') x--;
            while(x<0){
                if(a[i]=='T') x++;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        i=0; j=0; x=k;
        while(j<n){
            if(a[j]=='F') x--;
            while(x<0){
                if(a[i]=='F') x++;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};