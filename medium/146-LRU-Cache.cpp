//  i think we'll definitely need a hashmap
//      that'll give O(1) get and put, but not evict - need to track least recently used
//      could use a minheap, but in the case where we have a hit how would we find it?
//      actually nvm heap insert would be logn

//  ok watched neetcode vid yesterday and attempting now
//  basically, we want to keep a hashmap of key : node pairs and a doubly linked list
//  so map[key] will point to that value in the doubly linked list
//  the start of our list will be the least recently used, and the end the most recently used
//  so while we arent at capacity, just push nodes to the end of the list
//      also we will need a start and end dummy node for O(1) lookup for the lru element and mru insert
//  when we are at capacity and we insert an element:
//  if its a hit
//      find the existing node
//      set the next pointer for the previous node for the existing nodes next node
//      set the previous node for the next node to the previous node of the existing node
//      then, put the existing node in the front of the list,
//      aka between start and the lru node
//      updata the pointer in the hashtable if needed
//  if its a miss
//      we want to evict the least recently used, aka the first node in our list
//      erase the hash table entry for the lru node
//      replace the nodes key:value pair with the new one
//      insert into hash table

//  bruh i did not realize 'get' also counts as a 'use'

//  Solved in 1 hour
//      Conecptually this problem isnt bad at all
//      Implementing it on the other hand..........
//      I also kept forgetting you have to INSERT into the MRU and EVICT from the LRU
//      and didnt realize 'get' required a reordering
//      basically just kept forgetting random things
//      im also running on like 5 hours of sleep and its 10pm so thats probably partially to blame
//  Time - O(n)
//  Space - O(n)

//  TODO: if you got time redo this with insertNode and deleteNode functions, should make the code really clean
//      and on a fresh brain remembering when we're doing lru/mru

struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;
    Node() : key(0), value(0), next(nullptr), prev(nullptr) {}
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
    Node(int k, int v, Node* n, Node* p) : key(k), value(v), next(n), prev(p) {}
};

class LRUCache {

private:
    unordered_map<int, Node*> map;
    int cap;
    int size;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            cout << "notfound\n";
            return -1;
        }

        //  Get the curNode and its surrounding nodes
        Node* curNode = map[key];
        Node* prevNode = curNode->prev;
        Node* nextNode = curNode->next;

        //  "Erase" the node from the list
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        //  Insert the node into the MOST recently used spot
        prevNode = tail->prev;
        nextNode = tail;
        curNode->next = nextNode;
        curNode->prev = prevNode;
        prevNode->next = curNode;
        nextNode->prev = curNode;

        return map[key]->value;
    }
    
    void put(int key, int value) {
        //  Cache Miss
        if (map.find(key) == map.end()) {

            //  Capacity not full
            if (size < cap) {
                //  Get all our node pointers
                Node* curNode = new Node(key, value);
                Node* prevNode = tail->prev;
                Node* nextNode = tail;

                //  Update node pointers
                prevNode->next = curNode;
                nextNode->prev = curNode;
                curNode->next = nextNode;
                curNode->prev = prevNode;
                map[key] = curNode;
                size++;
            }

            //  Capacity full, need to evict LRU AND insert cur into MOST recently used
            else {
                //  Get LRU node and its next/prev
                Node* prevNode = head;
                Node* lruNode = head->next;
                Node* nextNode = head->next->next;

                //  Erase LRU node
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                map.erase(lruNode->key);

                //  Create new node and insert as MRU
                Node* curNode = new Node(key, value);
                prevNode = tail->prev;
                nextNode = tail;

                curNode->next = nextNode;
                curNode->prev = prevNode;
                prevNode->next = curNode;
                nextNode->prev = curNode;
                map[key] = curNode;
            }
        }

        //  Cache Hit 
        else {

            //  "Erase" the node from the list
            Node* curNode = map[key];
            Node* prevNode = curNode->prev;
            Node* nextNode = curNode->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            //  "Insert" the node into the mru spot
            prevNode = tail->prev;
            nextNode = tail;

            prevNode->next = curNode;
            nextNode->prev = curNode;
            curNode->prev = prevNode;
            curNode->next = nextNode;
            curNode->value = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */