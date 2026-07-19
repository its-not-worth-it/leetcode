class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(),  mod=1e9+7; long long ans=0;
        vector<int> pre(n), post(n); stack<int> s,t;
        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()]>arr[i]) s.pop();
            while(!t.empty() and arr[t.top()]>=arr[n-i-1]) t.pop();
            if(s.empty()) pre[i]=-1;
            else pre[i]=s.top();
            if(t.empty()) post[n-1-i]=n;
            else post[n-1-i]=t.top();
            s.push(i); t.push(n-i-1);
        }
        // for(int i:pre) cout<<i<<" ";
        // cout<<endl;
        // for(int i:post) cout<<i<<" ";

        for(int i=0;i<n;i++){
            ans+= ( ( (long long)(i-pre[i])*(post[i]-i)*arr[i] )%mod );
            ans%=mod;
        }


        return ans;
    }
};