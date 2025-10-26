class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        unordered_map<string, vector<string>> patternMap;
        int L = beginWord.length();
        for (string word : wordSet) {
            for (int i = 0; i < L; i++) {
                string pattern = word.substr(0, i) + '*' + word.substr(i + 1);
                patternMap[pattern].push_back(word);
            }
        }

        // BFS queue: {word, steps}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord)
                return steps;

            for (int i = 0; i < L; i++) {
                string pattern = word.substr(0, i) + '*' + word.substr(i + 1);

                for (string neighbor : patternMap[pattern]) {
                    if (!visited.count(neighbor)) {
                        visited.insert(neighbor);
                        q.push({neighbor, steps + 1});
                    }
                }

                // Optional optimization: clear pattern after use to save time
                patternMap[pattern].clear();
            }
        }

        return 0; // No path found
    }
};