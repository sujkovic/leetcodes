//      a
//      |
//      p
//      |
//     "p"
//   /  | \
//  e   l  a
//      |
//     "e"

//  Solved in 38 minutes
//      - the last 15 minutes of that was debugging memory leak only to realize
//       in Trie() i was doing "Node* root =" instead of "root ="

//  Space - O(m) where m is the total of all letters in inputted words
//      - worst case theres no overlapping letters
//  Time - O(n) for all operations where n is the max length of a word (height of tree)

//  Using vec[26]
//      Time - beats 36%
//      Space - beats 13%

/*
class Trie {
public:
    struct Node {
        char letter;
        bool isWord;
        vector<Node*> children;
        Node(char inputLetter) {
            letter = inputLetter;
            children = vector<Node*>(26, nullptr);
            isWord = false;
        }
    };

    Node* root;

    Trie() {
        root = new Node('.');
    }

    void insert(string word) {
        Node* curNode = root;
        for (int i = 0; i < word.length(); i++) {
            if (curNode->children[word[i] - 'a'] == nullptr) {
                Node* newNode = new Node(word[i]);
                curNode->children[word[i] - 'a'] = newNode;
            }
            curNode = curNode->children[word[i] - 'a'];
        }

        curNode->isWord = true;
    }

    bool search(string word) {
        Node* curNode = root;

        for (int i = 0; i < word.length(); i++) {
            if (curNode->children[word[i] - 'a'] != nullptr) {
                curNode = curNode->children[word[i] - 'a'];
            }
            else {
                return false;
            }
        }

        if (curNode->isWord) {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix) {
        Node* curNode = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (curNode->children[prefix[i] - 'a'] != nullptr) {
                curNode = curNode->children[prefix[i] - 'a'];
            }
            else {
                return false;
            }
        }

        return true;
    }
};
*/

//  Using map
//      Time - beats 24%
//      Spae - Beats 89%

class Trie
{
public:
    struct Node
    {
        char letter;
        bool isWord;
        unordered_map<char, Node *> children;
        Node(char letter) : letter(letter), isWord(false) {}
    };

    Node *root;

    Trie()
    {
        root = new Node('.');
    }

    void insert(string word)
    {
        Node *curNode = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (curNode->children.find(word[i]) != curNode->children.end())
            {
            }
            else
            {
                Node *newNode = new Node(word[i]);
                curNode->children[word[i]] = newNode;
            }
            curNode = curNode->children[word[i]];
        }

        curNode->isWord = true;
    }

    bool search(string word)
    {
        Node *curNode = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (curNode->children.find(word[i]) != curNode->children.end())
            {
                curNode = curNode->children[word[i]];
            }
            else
            {
                return false;
            }
        }

        if (curNode->isWord)
        {
            return true;
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        Node *curNode = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (curNode->children.find(prefix[i]) != curNode->children.end())
            {
                curNode = curNode->children[prefix[i]];
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */