class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())
            return "";
            
        unordered_map<char, int> seen, window;
        for (const char& c : t) {
            seen[c]++;
        }

        int have = 0, need = seen.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0, r = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (seen.contains(c) && window[c] == seen[c]) {
                have++;
            }

            while  (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if (seen.contains(s[l]) && window[s[l]] < seen[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
