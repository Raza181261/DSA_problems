class LFUCache {
private:
    struct Node {
        int key, val, freq;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };
    
    struct DLList {
        Node* head;
        Node* tail;
        int size;
        DLList() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addNode(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }
        void removeNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
        Node* removeTail() {
            if (size == 0) return nullptr;
            Node* node = tail->prev;
            removeNode(node);
            return node;
        }
    };
    
    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLList*> freqList;

    void updateFreq(Node* node) {
        int freq = node->freq;
        freqList[freq]->removeNode(node);
        if (freqList[freq]->size == 0 && minFreq == freq) minFreq++;
        node->freq++;
        if (!freqList.count(node->freq)) freqList[node->freq] = new DLList();
        freqList[node->freq]->addNode(node);
    }
    
public:
    LFUCache(int capacity_) {
        capacity = capacity_;
        minFreq = 0;
    }
    
    int get(int key) {
        if (!keyNode.count(key)) return -1;
        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyNode.count(key)) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        } else {
            if (keyNode.size() == capacity) {
                Node* nodeToRemove = freqList[minFreq]->removeTail();
                keyNode.erase(nodeToRemove->key);
                delete nodeToRemove;
            }
            Node* newNode = new Node(key, value);
            keyNode[key] = newNode;
            if (!freqList.count(1)) freqList[1] = new DLList();
            freqList[1]->addNode(newNode);
            minFreq = 1;
        }
    }
};
