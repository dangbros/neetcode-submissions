class LRUCache {
public:
    struct Node{
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* afterNode = node->next;

        prevNode->next = afterNode;
        afterNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* currentAfterHead = head->next;
        head->next = node;
        node->next = currentAfterHead;
        node->prev = head;
        currentAfterHead->prev = node;
    }

    LRUCache(int capacity_) {
        capacity = capacity_;
        mpp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head; 
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }
    
    void put(int key, int val) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->value = val;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size() == capacity){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            Node* node = new Node(key, val);
            mpp[key] = node;
            insertAfterHead(node);
        }
    }
};
