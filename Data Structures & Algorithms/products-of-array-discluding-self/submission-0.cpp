class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        bool hasZero = false;
        for (int num : nums) {
            if (num != 0)
                prod *= num;
            else
                hasZero = true;
        }
        vector<int> prods;
        for (int num : nums) {
            if (num == 0)
                prods.push_back(prod);
            else if (hasZero)
                prods.push_back(0);
            else
                prods.push_back(prod / num);
        }
        return prods;
    }
};
