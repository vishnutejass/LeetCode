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
    
    bool sym(TreeNode*rootl,TreeNode*root2){
        if(!rootl&&!root2){
            return true;
        }
        if((!rootl&&root2)||(rootl && !root2)||(rootl->val!=root2->val)){
            return false;
        }
    
       return sym(rootl->right ,root2->left) && sym(rootl->left , root2->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
      
     
        
       return sym(root->left,root->right);
    }
};


// class Solution {
// public:

//     bool solve(TreeNode* r1 ,TreeNode* r2){

//         if(!r1 && !r2) return true;

//         if((r1 && !r2) || (r2 && !r1)  || r1->val!=r2->val){
//             // cout<<r1->val<<" "<<r2->val;
//             return false;
//         };

//         return solve(r1->right ,r2->left) && solve(r1->left , r2->right);
//     }
//     bool isSymmetric(TreeNode* root) {
        
//         return solve(root->left ,root->right);
//     }
// };