class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;

        for (string path : paths) {
            stringstream ss(path);
            string dir, file;

            ss >> dir;

            while (ss >> file) {
                int pos = file.find('(');

                string name = file.substr(0, pos);
                string content = file.substr(pos + 1, file.size() - pos - 2);

                mp[content].push_back(dir + "/" + name);
            }
        }

        vector<vector<string>> ans;

        for (auto it : mp) {
            if (it.second.size() > 1) {
                ans.push_back(it.second);
            }
        }

        return ans;
    }
};