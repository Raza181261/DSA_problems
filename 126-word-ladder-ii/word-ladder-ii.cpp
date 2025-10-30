class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;
            for (int i = 0; i < sz; ++i) {
                string cur = q.front(); q.pop();
                string nxt = cur;

                for (int pos = 0; pos < (int)nxt.size(); ++pos) {
                    char old = nxt[pos];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == old) continue;
                        nxt[pos] = ch;
                        if (!dict.count(nxt)) continue;

                        if (!visited.count(nxt)) {
                            parents[nxt].push_back(cur);
                            if (!levelVisited.count(nxt)) {
                                levelVisited.insert(nxt);
                                q.push(nxt);
                            }
                        } else if (levelVisited.count(nxt)) {
                            parents[nxt].push_back(cur);
                        }

                        if (nxt == endWord) found = true;
                    }
                    nxt[pos] = old;
                }
            }
            for (auto &w : levelVisited) visited.insert(w);
        }

        if (!parents.count(endWord) && beginWord != endWord) return {};

        vector<string> path;
        function<void(string)> dfs = [&](string word) {
            path.push_back(word);
            if (word == beginWord) {
                vector<string> temp(path.rbegin(), path.rend());
                res.push_back(temp);
            } else {
                for (auto &p : parents[word]) dfs(p);
            }
            path.pop_back();
        };

        dfs(endWord);
        return res;
    }
};
