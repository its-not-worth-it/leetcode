class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        unordered_map<string,int> m;
        int a=beginWord.size();
        for(string i: w) m[i]=0;
        if(!m.count(endWord)) return 0;
        m[endWord]=0;
        queue<string> q; m[beginWord]=1; q.push(beginWord);
        while(!q.empty()){
            string x=q.front(), temp; q.pop();
            for(int i=0;i<a;i++){
                temp=x;
                for(int j=97; j<=122; j++){
                    if(j!=x[i]){
                        temp[i]=j;
                        if(m.count(temp)){
                            if(m[temp]==0){
                                m[temp]=m[x]+1;
                                q.push(temp);
                            }
                        }
                    }
                }
            }
        }
        return m[endWord];
    }
};