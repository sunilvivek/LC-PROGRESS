#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int longest = 0;

        for (auto it = freq.begin(); it != freq.end(); ++it) {
            auto nextIt = next(it);

            if (nextIt != freq.end() && nextIt->first == it->first + 1) {
                longest = max(longest, it->second + nextIt->second);
            }
        }

        return longest;
    }
};
