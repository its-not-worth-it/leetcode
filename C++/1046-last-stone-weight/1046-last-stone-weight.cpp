class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        priority_queue<int> q;
        for(int i:stones){
            q.push(i);
        }int a,b;

        while(q.size()>1){
            a=q.top();q.pop();
            b=q.top();q.pop();
            if(a==b) continue;
            else{
                a=(a>b?a-b:b-a);
                q.push(a);
            }

        }
        return q.size()?q.top():0;
    }
};