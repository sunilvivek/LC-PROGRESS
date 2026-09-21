class Solution {
public:
    int longestPalindrome(string s) {
        int frequency[128] = {0};

        for (char ch : s) {
            frequency[ch]++;
        }

        int result = 0;
        bool oddFound = false;

        for (int i = 0; i < 128; i++) {
            result += (frequency[i] / 2) * 2;

            if (frequency[i] % 2 != 0) {
                oddFound = true;
            }
        }

        if (oddFound) {
            result++;
        }

        return result;
    }
};
