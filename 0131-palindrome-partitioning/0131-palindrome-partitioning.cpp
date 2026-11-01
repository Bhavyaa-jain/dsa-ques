
class Solution {
public:
    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void getAllParts(string s, vector<string>& partitions,
                     vector<vector<string>>& ans) {

        // Base case
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.size(); i++) {

            string parts = s.substr(0, i + 1);

            if (isPalin(parts)) {

                partitions.push_back(parts);

                getAllParts(s.substr(i + 1), partitions, ans);

                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);

        return ans;
    }
};
