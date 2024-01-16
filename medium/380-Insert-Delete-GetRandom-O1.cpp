//  only things with O(1) insert/delete are set and hashmap
//  then need a way to randomize choosing smtn in it
//  problem is they arent ordered, so we cant index into them by order
//  if they were ordered, insert/remove would be O(logn)
//  so need to use another data struct or smtn so that we can index

//  ok so since there is at most 10,000 calls, we can just make a vector of size 10,000
//  we use this vector for the getRandom, and the vector will store values
//  then we use a hashmap of value : vec index for the insert/remove
//  just realized the range of vals is int so we will need longs

//  got to the rand method and realized i am not accounting for empty values in the array
//  looked at solution, realized when you remove, you just replace it with last item in vec

//  Time - O(1)
//  Space - O(n)

//  Solved in 50 minutes, that was awful kept having small bugs from just being careless 
//  and lazy, need to spend more time on thought process and being rly in depth with it
//  for these types of problems next time

class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<long int, int> map;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false;
        }

        vec.push_back(val);
        map[val] = vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false;
        }
        if (vec.size() == 1) {
            vec.pop_back();
            map.erase(val);
            return true;
        }
        
        int index = map[val]; 
        vec[index] = vec[vec.size() - 1];
        vec.pop_back();
        map[vec[index]] = index;
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */