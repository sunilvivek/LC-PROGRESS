class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;

    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void solve(string s, int start) {
        if (start == s.length()) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));

                solve(s, i + 1);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;
    }
};

