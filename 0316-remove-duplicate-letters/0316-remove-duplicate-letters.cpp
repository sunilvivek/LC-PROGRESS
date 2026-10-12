class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26] = {0};
        bool used[26] = {false};
        string st = "";

        // Store the last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Skip if the character is already included
            if (used[c - 'a'])
                continue;

            // Remove larger characters if they appear again later
            while (!st.empty() && st.back() > c &&
                   last[st.back() - 'a'] > i) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[c - 'a'] = true;
        }

        return st;
    }
};
