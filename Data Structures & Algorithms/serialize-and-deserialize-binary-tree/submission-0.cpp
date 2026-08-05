
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Serialize
    string serialize(TreeNode* root) {
        string s;
        helper(root, s);
        return s;
    }

    void helper(TreeNode* root, string &s) {
        if (!root) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";
        helper(root->left, s);
        helper(root->right, s);
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }

    TreeNode* build(stringstream &ss) {
        string val;
        getline(ss, val, ',');

        if (val == "N")
            return NULL;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = build(ss);
        root->right = build(ss);

        return root;
    }
};