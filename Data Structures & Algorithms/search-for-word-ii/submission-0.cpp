class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string &word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->child[idx])
                    node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->word = word;
        }

        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& ans) {
        char c = board[i][j];

        if (c == '#' || node->child[c - 'a'] == nullptr)
            return;

        node = node->child[c - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#';

        int m = board.size();
        int n = board[0].size();

        if (i > 0) dfs(board, i - 1, j, node, ans);
        if (j > 0) dfs(board, i, j - 1, node, ans);
        if (i < m - 1) dfs(board, i + 1, j, node, ans);
        if (j < n - 1) dfs(board, i, j + 1, node, ans);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> ans;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};