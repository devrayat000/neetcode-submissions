class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto i : nums) {
            if (seen.count(i) > 0) {
                return true;
            }
            seen.insert(i);
        }
        return false;
    }
};