class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {

            // Duplicate exists within distance k
            if (window.count(nums[i])) {
                return true;
            }

            window.insert(nums[i]);

            // Keep only last k elements
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
        }

        return false;
    }
};
