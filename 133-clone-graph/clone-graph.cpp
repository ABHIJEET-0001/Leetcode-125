class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        // Base case
        if (node == NULL) return NULL;

        // If already cloned
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create new node
        Node* clone = new Node(node->val);

        // Store mapping
        mp[node] = clone;

        // Clone neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};