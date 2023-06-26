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
#include<queue>
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
       queue<TreeNode*>q;
        q.push(root);
        
        int msum=INT_MIN;
        int count=0,ans=-1;
        while(!q.empty()){
          int sum=0;
            count++;
            int s=q.size();
            
            while(s--){
                TreeNode*f=q.front();
                q.pop();
                sum=sum+f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
           if(msum<sum){
               msum=sum;
               ans=count;
               
           } 
        }
        return ans;
    }
};