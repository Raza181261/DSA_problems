class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        vector<string> result;

        for (int i = 0; i + 10 <= s.size(); ++i) {
            string seq = s.substr(i, 10);
            count[seq]++;
        }

        for (auto &p : count) {
            if (p.second > 1) {
                result.push_back(p.first);
            }
        }

        return result;
    }
};
