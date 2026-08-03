class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            } 
        }

        if (target >= nums[l] && target <= nums[r]) {
            r = nums.size() - 1;
        } else {
            l = 0;
            r--;
        }
        return search(nums, target, l, r);
    }
private:
    int search(vector<int>& nums, int target, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target < nums[m]) {
                r = m - 1;
            } else if (target > nums[m]) {
                l = m + 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};
