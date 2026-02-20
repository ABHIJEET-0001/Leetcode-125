class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if(root == nullptr)
            return;

        inorder(root->left, result);   // Left proeply can you solve it 
        result.push_back(root->val);   // Root that is aslo solve it 
        inorder(root->right, result);  // Right that is very coorect solve it 
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};