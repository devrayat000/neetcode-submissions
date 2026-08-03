class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;

        int l = 0, maxx = 0;
        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;
            maxx = max(maxx, count[s[r]]);
            while ((r - l + 1) - maxx > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
