class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root != nullptr) {
            
            // Both values are smaller than root
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            
            // Both values are greater than root
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            
            // Values split around root, or root equals p/q
            else {
                return root;
            }
        }
        
        return nullptr;
    }
};