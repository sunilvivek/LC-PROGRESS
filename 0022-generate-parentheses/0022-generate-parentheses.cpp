#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void solve(string s, int open, int close, int n) {

        // We have used all brackets
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add '('
        if (open < n) {
            solve(s + "(", open + 1, close, n);
        }

        // Add ')'
        if (close < open) {
            solve(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        ans.clear();

        solve("", 0, 0, n);

        return ans;
    }
};