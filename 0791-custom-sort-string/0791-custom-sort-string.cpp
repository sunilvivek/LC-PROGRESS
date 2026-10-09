class Solution {
public:
    string customSortString(string order, string s) {
        int freq[26] = {0};

        // Count characters in s
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        // Add characters according to order
        for (char c : order) {
            while (freq[c - 'a'] > 0) {
                ans += c;
                freq[c - 'a']--;
            }
        }

        // Add remaining characters
        for (char c = 'a'; c <= 'z'; c++) {
            while (freq[c - 'a'] > 0) {
                ans += c;
                freq[c - 'a']--;
            }
        }

        return ans;
    }
};