// Q. Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_set<int> &visited, unordered_map<int, Node*> &newGraph){
        Node* cloneNode = new Node(node->val);
        newGraph[node->val] = cloneNode;
        visited.insert(node->val);
        for(auto &n : node->neighbors){
            if(!visited.count(n->val))
                dfs(n, visited, newGraph);
            //if visited, then it is already present in the map
            cloneNode->neighbors.push_back(newGraph[n->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return {};
        unordered_set<int> visited;
        unordered_map<int, Node*> newGraph;
        dfs(node, visited, newGraph);
        return newGraph[node->val];
    }
};