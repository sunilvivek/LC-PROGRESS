class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<vector<int>> answer(2);

        // Elements in nums1 but not nums2
        for (int x : set1) {
            if (set2.find(x) == set2.end()) {
                answer[0].push_back(x);
            }
        }

        // Elements in nums2 but not nums1
        for (int x : set2) {
            if (set1.find(x) == set1.end()) {
                answer[1].push_back(x);
            }
        }

        return answer;
    }
};