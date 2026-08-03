class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.front() < nums.back()) {
            return nums.front();
        }
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            cout << m << endl;
            if (nums[m] < nums[l] && nums[m] < nums[r]) {
                return nums[m];
            } else if (nums[m] > nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return nums[l];
    }
};
