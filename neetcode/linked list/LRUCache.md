LRU Cache
Solved
Implement the Least Recently Used (LRU) cache class LRUCache. The class should support the following operations

LRUCache(int capacity) Initialize the LRU cache of size capacity.
int get(int key) Return the value corresponding to the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the introduction of the new pair causes the cache to exceed its capacity, remove the least recently used key.
A key is considered used if a get or a put operation is called on it.

Ensure that get and put each run in
O
(
1
)
O(1) average time complexity.

Example 1:

Input:
["LRUCache", [2], "put", [1, 10], "get", [1], "put", [2, 20], "put", [3, 30], "get", [2], "get", [1]]

Output:
[null, null, 10, null, null, 20, -1]

Explanation:
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 10); // cache: {1=10}
lRUCache.get(1); // return 10
lRUCache.put(2, 20); // cache: {1=10, 2=20}
lRUCache.put(3, 30); // cache: {2=20, 3=30}, key=1 was evicted
lRUCache.get(2); // returns 20
lRUCache.get(1); // return -1 (not found)

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
```
