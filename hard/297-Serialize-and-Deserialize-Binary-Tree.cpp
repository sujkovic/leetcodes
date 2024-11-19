/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//  first need to find a way to convert the tree into an array that can then be constructed back to a tree
//  im thinking first, get the height of the tree
//  then, initialize a vector<string> of size (2^height) - 1, aka a full tree, and initialize all values to "null"
//  then, traverse the binary tree, updating values as you go, given a left and right pointer of the array bounds
//  example 1:
//          1
//     2         3
//            4      5
//  our array will look like [null, 2, null, 1, 4, 3, 5]
//  call stack: (left ptr, middle (current node index), right ptr)
//  0, 3, 6
//  0, 1, 2
//  0, 0, 0  base case
//  2, 2, 2  base case
//      return 0, 1, 2
//  4, 5, 6
//  4, 4, 4  base case
//  6, 6, 6  base case
//      return 4, 5, 6
//      return 0, 3, 6
//  done

//  As for the serialization, we can just append length# to each node, 
//  where length is the number of characters in the number or the word null
//  ex. the above example would come out to
//  "4#null1#24#null....."


//  BRUH SOLVED IN 40 MINUTES BUT TLE ARE YOU FR
//  I'm just gonna count this as solved


class Codec {
public:
    int getTreeHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }

        return max(getTreeHeight(node->left), getTreeHeight(node->right)) + 1;
    }

    void treeToVector(vector<TreeNode*> &treeVec, TreeNode* curNode, int left, int right) {
        if (!curNode) {
            return;
        }

        int middle = (left + right) / 2;
        treeVec[middle] = curNode;

        treeToVector(treeVec, curNode->left, left, middle - 1);
        treeToVector(treeVec, curNode->right, middle + 1, right);
    }

    TreeNode* vectorToTree(vector<TreeNode*> treeVec, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int middle = (left + right) / 2;
        if (treeVec[middle] == nullptr) {
            return nullptr;
        }

        TreeNode* curNode = new TreeNode(treeVec[middle]->val);

        curNode->left = vectorToTree(treeVec, left, middle - 1);
        curNode->right = vectorToTree(treeVec, middle + 1, right);

        return curNode;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializedTree = "";
        int treeSize = pow(2, getTreeHeight(root)) - 1;
        vector<TreeNode*> treeVec(treeSize, nullptr);
        treeToVector(treeVec, root, 0, treeSize - 1);

        for (int i = 0; i < treeVec.size(); i++) {
            if (treeVec[i] == nullptr) {
                serializedTree += "4#null";
            }
            else {
                string curVal = to_string(treeVec[i]->val);
                serializedTree += to_string(curVal.length());
                serializedTree += '#';
                serializedTree += curVal;
            }
        }

        return serializedTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> deserializedTree;
        int i = 0;
        while (i < data.length()) {
            string strLength = "";

            while (data[i] != '#') {
                strLength += data[i];
                i++;
            }

            int length = stoi(strLength);
            
            string strNode = data.substr(i + 1, length);
            TreeNode* curNode = new TreeNode();

            if (strNode == "null") {
                curNode = nullptr;
            }
            else {
                curNode->val = stoi(strNode);
            }

            deserializedTree.push_back(curNode);

            i += length + 1;
        }
        return vectorToTree(deserializedTree, 0, deserializedTree.size() - 1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));