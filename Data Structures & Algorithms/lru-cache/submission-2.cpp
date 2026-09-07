class LRUCache {
public:
    struct Node{
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    map<int, Node*> mpp;
    Node* head;
    Node* tail;
    int cap;

    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* currAfterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = currAfterHead;
        currAfterHead->prev = node;
    }

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
        mpp.clear();
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;

        Node* node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            deleteNode(node);
            insertAfterHead(node);
            node->val = value;
        }
        else{
            if(mpp.size() == cap){
                Node* node = tail->prev;
                deleteNode(node);
                mpp.erase(node->key);
                delete node;
            }
            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};
