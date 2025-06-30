146. LRU Cache
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1); // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2); // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1); // return -1 (not found)
lRUCache.get(3); // return 3
lRUCache.get(4); // return 4

```
class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k),val(v),prev(nullptr),next(nullptr){};
};

class LRUCache {
    private:
    int cap;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node * previous = node->prev;
        Node * nxt = node->next;
        previous->next = nxt;
        nxt->prev = previous;
    }

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->next = right;
        node->prev = prev;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        Node* newnode = new Node(key,value);
        cache[key] = newnode;
        insert(newnode);

        if(cache.size() > cap){
            Node * lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete(lru);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
