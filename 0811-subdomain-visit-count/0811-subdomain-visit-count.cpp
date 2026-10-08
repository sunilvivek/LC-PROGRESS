class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mp;

        for (string s : cpdomains) {

            // Get visit count
            int space = s.find(' ');
            int count = stoi(s.substr(0, space));

            // Get domain
            string domain = s.substr(space + 1);

            // Add complete domain
            mp[domain] += count;

            // Add subdomains
            while (domain.find('.') != string::npos) {
                domain = domain.substr(domain.find('.') + 1);
                mp[domain] += count;
            }
        }

        vector<string> ans;

        for (auto x : mp) {
            ans.push_back(to_string(x.second) + " " + x.first);
        }

        return ans;
    }
};
