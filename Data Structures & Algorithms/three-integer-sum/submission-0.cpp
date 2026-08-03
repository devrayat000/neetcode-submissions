class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sums;
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            int target = -nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    sums.push_back({nums[i], nums[j], nums[k]});
                    break;
                } else if (nums[j] + nums[k] < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return sums;
    }
};
