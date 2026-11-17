class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> groups;
        
        for (const string& word : words) {
            string even = "";
            string odd = "";
            
            for (int i = 0; i < word.size(); ++i) {
                if (i % 2 == 0) {
                    even += word[i];
                } else {
                    odd += word[i];
                }
            }
            
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            
            // Combine with a delimiter to create a unique key
            groups.insert(even + "#" + odd);
        }
        
        return groups.size();
    }
};