class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0, r = 0, len = 0;
        while (r < s.length()) {
            while (seen.contains(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            len = max(r - l + 1, len);
            r++;
        }
        return len;
    }
};
