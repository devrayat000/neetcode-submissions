class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        while (s.length() > 0) {
            size_t pos = s.find("#");
            int length = stoi(s.substr(0, pos));
            decoded.push_back(s.substr(pos + 1, pos + length - 1));
            s = s.substr(pos + length + 1);
        }
        return decoded;
    }
};
