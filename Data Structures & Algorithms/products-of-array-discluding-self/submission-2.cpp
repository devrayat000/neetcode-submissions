class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int numZeros = 0;
        bool hasNonZero = false;
        for (int num : nums) {
            if (num != 0) {
                prod *= num;
                hasNonZero = true;
            }
            else
                numZeros++;
        }
        vector<int> prods(nums.size());

        if (!hasNonZero || numZeros > 1) {
            return prods;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                prods[i] = prod;
            else if (numZeros)
                prods[i] = 0;
            else
                prods[i] = prod / nums[i];
        }
        return prods;
    }
};
