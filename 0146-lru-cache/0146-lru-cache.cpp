class LRUCache {
public:

    class Node{
        public:
            int key, val;
            Node* prev;
            Node* next;

            Node(int k, int v){
                key = k; 
                val = v;
                prev = next = NULL;
            }
    };

    Node* head;
    Node* tail;
    int cap;

    unordered_map<int,Node*> mp;


    LRUCache(int capacity) {    
        cap = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head -> next = tail;
        tail -> prev = head;
    }

    void removeNode(Node* node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void insertTail(Node* node){
        node -> prev = tail -> prev;
        node -> next = tail;

        tail -> prev -> next = node;
        tail -> prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];

        removeNode(node);
        insertTail(node);

        return node -> val;
    }
    
    void put(int key, int value) {
        //Key already exists
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node -> val = value;

            removeNode(node);
            insertTail(node);

            return;
        }

        // Cache full
        if(mp.size() == cap){
            Node* lru = head -> next;
            removeNode(lru);
            mp.erase(lru -> key);
            delete lru;
        }
        Node* node = new Node(key, value);
        insertTail(node);
        mp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */