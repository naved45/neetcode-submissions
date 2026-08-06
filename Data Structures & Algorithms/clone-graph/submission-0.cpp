

#include <bits/stdc++.h>
using namespace std;

// LeetCode already defines Node, so don't redefine it here.
// Just use the given Node structure.

class Solution {
public:
    unordered_map<Node*, Node*> mp; // old node -> new node mapping
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        if (mp.find(node) != mp.end()) {
            return mp[node]; // already cloned
        }
        
        Node* clone = new Node(node->val);
        mp[node] = clone;
        
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return clone;
    }
};
