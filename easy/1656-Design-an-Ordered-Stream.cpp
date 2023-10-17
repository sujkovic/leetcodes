//  Constructor //
//  Keep pointer var and vector
//  Init pointer to 0 and vec to blank vector of size n

//  Insert  //
//  set vec[idkey] = value
//  if ptr == idkey
//      return the contiguous list starting at ptr
//      set ptr to the next index after end of list
//  else 
//      return empty list

//  Time Complexity - O(n) - worst case we loop through entire vector of size n
//  Space Complexity - O(n) - Need to hold up to n items in vector
//  Solved in like 30-60 min this took way too long the description was confusing

class OrderedStream {
public:
    vector<string> vec;
    int ptr = 1;
    OrderedStream(int n) {
        vec = vector<string>(n + 1, "");
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        vec[idKey] = value;
        vector<string> curChunk;
        if (idKey == ptr) {
            while (ptr < vec.size() && vec[ptr] != "") {
                curChunk.push_back(vec[ptr]);
                ptr++;
            }
        }
        return curChunk;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */