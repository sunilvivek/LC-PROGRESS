class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for (int x : nums) {
            int index = abs(x) - 1;

            if (nums[index] < 0) {
                result.push_back(abs(x));
            } else {
                nums[index] = -nums[index];
            }
        }

        return result;
    }
};
