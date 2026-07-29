#include <bits/stdc++.h>
using namespace std;

// LeetCode already provides this definition, so you don’t need to redefine it.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;          // both null → same
        if (!p || !q) return false;         // one null → different
        if (p->val != q->val) return false; // values differ → different
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};
