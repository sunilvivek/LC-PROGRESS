
class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (mp.count(email))
                    unite(i, mp[email]);
                else
                    mp[email] = i;
            }
        }

        vector<vector<string>> merged(n);

        for (auto& [email, idx] : mp) {
            int root = find(idx);
            merged[root].push_back(email);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (string& email : merged[i])
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};
