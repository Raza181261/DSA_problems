class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            int sz = q.size();
            unordered_set<string> levelSeen;

            for (int i = 0; i < sz; ++i) {
                string cur = q.front();
                q.pop();

                if (isValid(cur)) {
                    result.push_back(cur);
                    found = true;
                }

                if (found) continue; // Only process current level
                for (int j = 0; j < cur.size(); ++j) {
                    if (cur[j] != '(' && cur[j] != ')') continue;
                    string next = cur.substr(0, j) + cur.substr(j + 1);
                    if (!visited.count(next)) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            if (found) break;
        }

        return result.empty() ? vector<string>{""} : result;
    }

private:
    bool isValid(const string& str) {
        int count = 0;
        for (char c : str) {
            if (c == '(') count++;
            else if (c == ')') {
                if (--count < 0) return false;
            }
        }
        return count == 0;
    }
};
