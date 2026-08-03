class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool hasZero = false, hasNonZero = false;
        for (int num : nums) {
            if (num != 0) {
                prod *= num;
                hasNonZero = true;
            }
            else
                hasZero = true;
        }
        vector<int> prods(nums.size());

        if (!hasNonZero) {
            return prods;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                prods[i] = prod;
            else if (hasZero)
                prods[i] = 0;
            else
                prods[i] = prod / nums[i];
        }
        return prods;
    }
};
