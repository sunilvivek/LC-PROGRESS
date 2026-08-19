class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26, 100);

        for (string& word : words) {
            vector<int> count(26, 0);

            for (char c : word) {
                count[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                common[i] = min(common[i], count[i]);
            }
        }

        vector<string> ans;

        for (int i = 0; i < 26; i++) {
            while (common[i]--) {
                ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;
    }
};