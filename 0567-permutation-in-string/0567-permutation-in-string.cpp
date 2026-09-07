class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        vector<int> count(26, 0);

        // Count characters in s1
        for (char c : s1)
            count[c - 'a']++;

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {
            // Add s2[right] to the window
            count[s2[right] - 'a']--;

            // Keep window size equal to s1.size()
            if (right - left + 1 > s1.size()) {
                count[s2[left] - 'a']++;
                left++;
            }

            // Check if window is a permutation of s1
            if (right - left + 1 == s1.size()) {
                bool valid = true;

                for (int i = 0; i < 26; i++) {
                    if (count[i] != 0) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    return true;
            }
        }

        return false;
    }
};
