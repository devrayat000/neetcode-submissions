class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (const int& num : nums) {
            hash.insert(num);
        }

        int maxLen = 0;
        for (const int& key : hash) {
            if (hash.contains(key - 1))
                continue;
            int currLen = 1;
            for (int i = key; hash.contains(i + 1); i++) {
                currLen++;
            }
            maxLen = max(currLen, maxLen);
        }
        return maxLen;
    }
};
