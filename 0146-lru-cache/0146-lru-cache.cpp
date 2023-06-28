class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node* prev;
            Node* next;
        
        Node(int _key,int _val) {
            key = _key;
            val = _val;
        }
    };
    
    // delcare head and tail
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    int cap;
    unordered_map<int, Node*> umap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addNode(Node * newnode) {
        Node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node * delnode) {
        Node * delprev = delnode -> prev;
        Node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    
    int get(int key) {
        if(umap.find(key) == umap.end()) return -1;
        
        Node* resNode = umap[key];
        
        int ans = resNode -> val;
        
        umap.erase(key);
        deleteNode(resNode);
        addNode(resNode);
        
        umap[key] = head -> next;
        
        return ans;
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end()) {
            Node* exisNode = umap[key];
            umap.erase(key);
            deleteNode(exisNode);
        }
        
        if(umap.size() == cap) {
            umap.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }
        
        addNode(new Node(key, value));
        umap[key] = head -> next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */