//  ["Hello", "World"] -> encoded string -> ["Hello", "World"]
//  "Hello"
//  Basically need to find some delimiter that wouldn't naturally come up in input 
//  Sat here thinking for 8 minutes

//  had to watch neetcode vid for this next part

//  we can use length of the next string + some symbol as a delimiter
//  this way we know when we see a number followed by a idk hashtag, the next 
//  string is the substr(hashtag index + 1, number)

//  Solved in 9 min
//  O(n)

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            string delimiter = to_string(strs[i].length()) + '#';
            result += delimiter;
            result += strs[i];
        }

        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;

        while (i < s.length()) {
            string strLength = "";
            while (s[i] != '#') {
                strLength += s[i];
                i++;
            }

            int length = stoi(strLength);
            result.push_back(s.substr(i + 1, length));
            i += length + 1;
        }

        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));