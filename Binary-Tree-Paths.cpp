/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void createPath(TreeNode* root, string& curPath, vector<string>& ans) {
        if (!root)
            return;
        int len = curPath.size();
        if (!root->left && !root->right) {
            curPath += to_string(root->val);
            ans.push_back(curPath);

        } else

        {
            curPath += (to_string(root->val) + "->");
            createPath(root->left, curPath,ans);
            // right subtree
            createPath(root->right, curPath,ans);
            
        }

        curPath.resize(len); //backtrack
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path;
        createPath(root, path, ans);
        return ans;
    }
};