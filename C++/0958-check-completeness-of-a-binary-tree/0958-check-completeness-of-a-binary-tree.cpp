/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int n=0, t;     bool f=false;
        while(!q.empty()){
            t=1<<n;
            while(!q.empty() and t--){
                // if(q.front()) cout<<q.front()->val<<" ";
                // else cout<<0<<" ";
                if(f and q.front() ) return false;
                if(q.front()) q.push(q.front()->left);
                if(q.front()) q.push(q.front()->right);
                if(!q.front()) f=true;
                q.pop();
            }
            // cout<<endl;
            n++;
        }
        return true;
    }
};