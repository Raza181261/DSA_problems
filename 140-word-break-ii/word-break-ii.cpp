class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo; // memoization for starting index
        
        function<vector<string>(int)> dfs = [&](int start) -> vector<string> {
            if (memo.count(start)) return memo[start];
            vector<string> result;
            if (start == s.size()) {
                result.push_back("");
                return result;
            }

            for (int end = start + 1; end <= s.size(); ++end) {
                string word = s.substr(start, end - start);
                if (dict.count(word)) {
                    vector<string> subs = dfs(end);
                    for (string &sub : subs) {
                        result.push_back(word + (sub.empty() ? "" : " " + sub));
                    }
                }
            }
            return memo[start] = result;
        };

        return dfs(0);
    }
};

