class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (const auto& str : strs) {
            res += to_string(str.size());
            res += '#';
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Move past '#'
            j++;

            // Get string
            result.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return result;
    }
};