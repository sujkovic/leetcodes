//  maintain a fifo queue and a product variable
//  if queue size <= k, push new num to front of queue queue and *= it to product
//  if queue size > k, /= product by queue.back, pop from back of queue, push new num to front of queue
//  ok just realized 0 might be a very annoying test case but we'll see
//  ok nvm i read the problem wrong, k is NOT given in constructor so need to change approach
//      cur at 6:30

//  instead maybe make a vector of ints prefixProduct, where arr[i] = arr[i - 1] * curNum
//  so to retrieve product of last k numbers, divide arr[arr.size - 1] by arr[arr.size - k]
//  actually idek if this would work cause of zero
//  could potentially have some sort of zero flag but that would still be O(k)
//  ok keep a prefixProduct vector, and anytime we encounter a zero,
//      set vec[i] to zero, but after that reset product to 1, so that next value isn't nullified
//      and add the current index to a stack of zero locations
//  this way anytime we call getProduct, we check in O(1) time if any of the last k elements were zero
//  and otherwise our math isn't all nullified by the existence of a zero

//  Solved in 35 min but the last 12 min was debugging the most confusing bug
//      for some reason in my first if statement in getProduct, if mostRecentZero is -1,
//      the result of the statement always comes out to true
//      so like if products size is 1 and k is 1, it should come out to -1 >= 0
//      that is false but was coming out true????!! i do not understand
//      I'm hyped I came up with the solution myself in 23 min tho
//  Time - O(1)
//  Space - O(1)

class ProductOfNumbers {
    private:
        vector<int> products;
        int curProduct = 1;
        int mostRecentZero = -1;
    public:
        ProductOfNumbers() {
            curProduct = 1;
            mostRecentZero = -1;
            products = {};
        }
        
        void add(int num) {
            if (num != 0) {
                curProduct *= num;
                products.push_back(curProduct);
            }
            else {
                products.push_back(0);
                curProduct = 1;
                mostRecentZero = products.size() - 1;
            }
        }
        
        int getProduct(int k) {
            if (mostRecentZero != -1 && mostRecentZero >= products.size() - k) {
                return 0;
            }
            else {
                //  edge case
                if (mostRecentZero == products.size() - k - 1 || products.size() == k) {
                    return products[products.size() - 1];
                }
                else {
                    return (products[products.size() - 1] / products[products.size() - k - 1]);
                }
            }
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */