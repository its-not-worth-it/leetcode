class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="", temp="";
        int one=0, i=0, j=0, t, n=s.size();
        
        while(i<n and s[i]=='0'){
            i++; j++;
        }
        while(i<n and one< k){
            ans.push_back(s[i]);
            if(s[i]=='1') one++; 
            i++;
        }
        if(one < k) return "";

        t=i-j;
        while(i < n){
            if(s[i]=='1') one++;
            i++;
            while(one > k) {
                if(s[j]=='1') one--;
                j++;
            }
            while(s[j]=='0' and j< i) j++;
            if(one==k and i-j < t){
                ans=s.substr(j,i-j); 
                t=i-j;
            }else if(one==k and i-j==t){
                temp=s.substr(j, i-j);
                if(temp < ans) ans=temp;
            }
        }



        return ans;
    }
};