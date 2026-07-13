class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        priority_queue<int, vector<int>,greater<int>> q;

        for(int i:arr2) m[i]=0;
        for(int i:arr1){
            if(m.count(i)) m[i]++;
            else q.push(i);
        }
        int j=0;
        for(int i:arr2){
            while(m[i]){
                arr1[j++]=i;
                m[i]--;
            }
        }
        while(!q.empty()){
            arr1[j++]=q.top();
            q.pop();
        }
        return arr1;
    }
};