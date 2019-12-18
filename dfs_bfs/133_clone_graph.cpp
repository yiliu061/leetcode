class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if (!node) return NULL; //!
        unordered_map<Node*, Node*> umap; //map the old node to it's new node
        queue<Node*> q{{node}};
        Node* newHead = new Node(node->val); //we need a newhead to return
        umap[node] = newHead;
        
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            for (Node* neighbor : curr->neighbors){
                if(!umap.count(neighbor)){
                    umap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                umap[curr]->neighbors.push_back(umap[neighbor]); //!

            }
        }    
        return newHead; 

    }
};
